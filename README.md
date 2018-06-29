# README

## Description

Rename files, mainly used when the filename is unknown.
Current support:
    zip, rar, docx, pptx, doc, pdf

## Module required

Wheel source: <http://www.lfd.uci.edu/~gohlke/pythonlibs/>

- [wheel](http://wheel.readthedocs.io/en/latest/)

[Bitbucket](https://bitbucket.org/pypa/wheel),
[wheel-0.26.0-py2.py3-none-any.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/wheel-0.26.0-py2.py3-none-any.whl),
[Doc](http://wheel.readthedocs.io/en/latest/)

- [numpy](http://www.numpy.org/)

[Github](https://github.com/numpy/numpy),
[numpy-1.13.0+mkl-cp27-cp27m-win32.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/numpy-1.13.0+mkl-cp27-cp27m-win32.whl),
[Doc](http://www.numpy.org/)

- [pypdf2](http://pythonhosted.org/PyPDF2/)

[Github](https://github.com/mstamy2/PyPDF2),
[PyPDF2-1.26.0-py2.py3-none-any.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/PyPDF2-1.26.0-py2.py3-none-any.whl),
[Doc](http://pythonhosted.org/PyPDF2/)

- [zipfile](https://docs.python.org/2/library/zipfile.html)

[Doc](https://docs.python.org/2/library/zipfile.html)

- [rarfile](https://rarfile.readthedocs.io/en/latest)

[Github](https://github.com/markokr/rarfile),
[rarfile-3.0-py2.py3-none-any.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/rarfile-3.0-py2.py3-none-any.whl),
[Doc](https://rarfile.readthedocs.io/en/latest)

- [python-docx](https://python-docx.readthedocs.io/en/latest)

[Github](https://github.com/python-openxml/python-docx),
[python_docx-0.8.6-py2.py3-none-any.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/python_docx-0.8.6-py2.py3-none-any.whl)
  & [lxml](https://github.com/lxml/lxml),
    [lxml-3.8.0-cp27-cp27m-win32.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/lxml-3.8.0-cp27-cp27m-win32.whl),
[Doc](https://python-docx.readthedocs.io/en/latest)

- [python-pptx](https://python-pptx.readthedocs.io/en/latest/)

[Github](https://github.com/scanny/python-pptx)
  & [Pillow](https://github.com/python-pillow/Pillow/),
[Doc](https://python-pptx.readthedocs.io/en/latest/)

- [olefile](http://olefile.readthedocs.io/en/latest/)

[Github](https://github.com/decalage2/olefile),
[olefile-0.44-py2.py3-none-any.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/vu0h7y4r/olefile-0.44-py2.py3-none-any.whl),
[Doc](http://olefile.readthedocs.io/en/latest/)

If work offline, download the crossponding wheel files and install with:
    `python pip-9.0.1-py2.py3-none-any.whl/pip install xxxxxxxx.whl`

## Usage

Compile the 'FIB parse module' by `make`. &
Run `python file_renamer.py` in the working directory.

## TODO

Deal with Chinese Language.
Have more test.

## Version

- v1.0 - 20170330:

  - First release, only support pdf files.
  - Replace invalid character in the title.

- v1.1 - 20170428:

  - BUG 001 fixed: Do nothing is the pdf's title is 'null'.
  - BUG 002 fixed: Append a random number incase override file with same name.
  - Extend support with `zip`, `rar`, `docx`, `pptx`, `doc` files.

- v1.2 - 20170504:

  - re-write '__rename_doc_file', according to [MS-DOC].pdf.
  - paesr 'FIB' structure in c code.
  - modify '__rename_file', incase for 'null' tgtname.

- v2.0 - 20170613:

  - BUG 003 fixed: Correct the OS name.
  - BUG 004 fixed: Close the file before rename it.
  - BUG 005 fixed: assign filename with the replaced one to update the filename.
  - Implemtation `parseZip.sh` in '__rename_zip_archive'.

- v2.1 - 20171101:

  - BUG 006 fixed: Use the first non-empty paragraph to rename the doc/docx file.
  - Retrive page content by `getPage(0).extractText()` and use the first non-empty line
        to rename the pdf file.
  - Rename the class to `FileRenamer`, and the module name to `file_renamer.py`.

- v2.2 - 20171107:

  - Add more parse for pdf files.
