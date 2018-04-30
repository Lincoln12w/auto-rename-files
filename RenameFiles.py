"""
Description:
    Rename files, mainly used when the filename is unknown.
    Current support:
        zip, rar, docx, pptx, doc, pdf

Author: lincoln12w
Github: https://github.com/Lincoln12w

Module:
    zipfile, rarfile, docx, pptx, OleFileIO_PL, PyPDF2

APIs:

Modify History
--------------
00a 07nov17 lzw Just create.
"""

import os
import platform
import ctypes

import zipfile
import rarfile
import docx
import pptx
import OleFileIO_PL  # support for doc file
import PyPDF2
from numpy.random import rand


class FileRenamer(object):
    """Rename file name.

    Rename Files according to their contents.
    Currently support:
        zip, rar, docx, pptx, doc, pdf

    Usage:
        >>> f = RenameFiles(file)
        >>> f.rename()
    """

    __os = platform.system()
    __ext = ''
    __filename = ''
    __supportos = {'Windows', 'Linux', 'Darwin'}
    __maxlen = 255

    def __init__(self, filename):
        self.__filename = filename
        if self.__os not in self.__supportos:
            print "OS %s is not support, use windows as default." % self.__os
            self.__os = 'Windows'
        ext = filename.split('.')[-1]
        if ext == filename or ext == filename[1:]:
            ext = None
        self.__ext = ext

    def __replace_invalid_char(self, filename):
        windows = {'\\', '/', ':', '*', '?', '"', '<', '>', '|', '\0'}
        linux = {'/', '\0'}
        darwin = {'\\', '/', '\0'}
        invalidchar = {'Windows': windows,
                       'Linux': linux,
                       'Darwin': darwin}
        for char in invalidchar[self.__os]:
            filename = filename.replace(char, '-')
        return filename

    def __rename_file(self, tgtname):
        if isinstance(tgtname, unicode):
            tgtname = tgtname.encode('utf-8')
        # In case of the file name already exist.
        randstr = str(int(rand() * 10000))
        if len(tgtname) > self.__maxlen:
            tgtname = tgtname[:self.__maxlen]
        while tgtname[-1] == '/':
            tgtname = tgtname[:-1]
        # tgtname = tgtname.split('/')[-1]
        tgtname = os.path.split(tgtname)[1]
        if tgtname:
            tgtname += '-' + randstr + '.' + self.__ext
            tgtname = self.__replace_invalid_char(tgtname)

            print "  Try to rename: %s\n             to: %s"\
                % (self.__filename, tgtname)

            try:
                os.rename(self.__filename, tgtname)
            except OSError:
                print "   Error: %s can not be renamed." % self.__filename
        else:
            print "    Error: %s can not be renamed." % self.__filename

    def __rename_pdf_file(self):
        try:
            actfile = file(self.__filename, 'rb')
        except IOError:
            print "    Error: %s can not open." % self.__filename
            return

        try:
            pdff = PyPDF2.PdfFileReader(actfile)
        except PyPDF2.utils.PdfReadError:
            print "    Error: %s is not a pdf file or cprrupted."\
                % self.__filename
            actfile.close()
            return

        content = pdff.getDocumentInfo().title

        # get the first non-empty line
        if content is None or content == '':
            contents = pdff.getPage(0).extractText().split('\n')
            for content in contents:
                if content == u' ' or content == u'1' or content == u'Page ':
                    continue
                if content:
                    break

        del pdff
        actfile.close()

        if content:
            self.__rename_file(content)

    def __rename_docx_file(self):
        try:
            docxf = docx.Document(self.__filename)
        except docx.opc.exceptions.PackageNotFoundError:
            print "    Error: %s is not a docx file or cprrupted."\
                % self.__filename
            return

        # get the first non-empty paragraph
        for paragraph in docxf.paragraphs:
            if paragraph.text:
                content = paragraph.text
                break

        if content:
            self.__rename_file(content)

        # Need close ?

    def __rename_pptx_file(self):
        try:
            pptxf = pptx.Presentation(self.__filename)
        except pptx.exc.PackageNotFoundError:
            print "    Error: %s is not a pptx file or cprrupted."\
                % self.__filename
            return

        title = pptxf.core_properties.title

        if title:
            self.__rename_file(title)

    class _Result(ctypes.Structure):
        _fields_ = [("offset", ctypes.c_int), ("size", ctypes.c_int),
                    ("utf_16", ctypes.c_int)]

    def __parse_fib(self, stream, table):
        lib = ctypes.cdll.LoadLibrary("./libparselib.so")
        lib.parse_fib.restype = ctypes.POINTER(self._Result)
        result = lib.parse_fib(stream, table)
        return result.contents.offset, result.contents.size, \
            result.contents.utf_16

    def __rename_doc_file(self):
        try:
            ole = OleFileIO_PL.OleFileIO(self.__filename)
        except IOError:
            print "    Error: %s is not a doc file or cprrupted."\
                % self.__filename
            return

        # Each Word Binary File must contain a stream called
        # "WordDocument" stream, and this stream must start with a
        # File Information Block (FIB).
        docstream = ole.openstream('worddocument').read()
        if ole.exists('1Table'):
            table = ole.openstream('1Table').read()
        else:
            table = ole.openstream('0Table').read()
            print "Use 0Table"

        # return the first cp in the mainstream
        offset, size, utf_16 = self.__parse_fib(docstream, table)

        if utf_16:
            text = docstream[offset: offset + 2 * size]
            text = text.decode('utf-16').encode('utf-8')
        else:
            offset /= 2
            text = docstream[offset:offset + size]

        # get the first non-empty paragraph
        paragraphs = text.split('\r')
        for paragraph in paragraphs:
            if paragraph:
                content = paragraph
                break

        author = ole.get_metadata().author

        ole.close()

        if content:
            filename = content
            if author is not None:
                filename += '-' + author
            self.__rename_file(filename)

    def __rename_zip_archive(self):
        try:
            zipf = zipfile.ZipFile(self.__filename, mode='r')
        except zipfile.BadZipfile:
            print "    Error: %s is not a zip file or cprrupted."\
                % self.__filename
            return

        content = zipf.namelist()
        zipf.close()

        if content:
            # docx, pptx, xlsx, vsdx are all compressed in zips.
            tmp = {name.split('/')[0] for name in content}
            if 'word' in tmp:
                self.__ext = 'docx'
                self.__rename_docx_file()
            elif 'ppt' in tmp:
                self.__ext = 'pptx'
                self.__rename_pptx_file()
            elif 'xl' in tmp:
                os.rename(self.__filename, self.__filename[:-3] + 'xlsx')
            elif 'visio' in tmp:
                os.rename(self.__filename, self.__filename[:-3] + 'vsdx')
            else:
                self.__rename_file(content[0])

    def __rename_rar_archive(self):
        try:
            rarf = rarfile.RarFile(self.__filename, mode='r')
        except rarfile.BadRarFile:
            print "    Error: %s is not a rar file or cprrupted."\
                % self.__filename
            return

        content = rarf.namelist()
        rarf.close()

        if content:
            self.__rename_file(content[0].split('/')[0])

    __ops = {
        'pdf': __rename_pdf_file,
        'docx': __rename_docx_file,
        'pptx': __rename_pptx_file,
        'doc': __rename_doc_file,
        'zip': __rename_zip_archive,
        'rar': __rename_rar_archive}

    def rename(self):
        """
        Rename supported filed API.
        """
        if os.path.isfile(self.__filename):
            renamefunc = self.__ops.get(self.__ext)
            if renamefunc:
                renamefunc(self)
            else:
                print "%s: extension not support." % (self.__filename)


def main():
    """
    Rename all files under the `pwd`.
    """
    for file_ in os.listdir('.'):
        if os.path.isfile(file_):
            print "@--->%s" % file_
            renamer = FileRenamer(file_)
            renamer.rename()

    print "\nDone!"

if __name__ == "__main__":
    main()
