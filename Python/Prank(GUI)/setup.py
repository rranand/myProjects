import sys
import os
from cx_Freeze import setup, Executable

base = None

os.environ["TCL_LIBRARY"] =r'C:\Users\rrohi\AppData\Local\Programs\Python\Python37-32\tcl\tcl8.6'
os.environ["TK_LIBRARY"] =r'C:\Users\rrohi\AppData\Local\Programs\Python\Python37-32\tcl\tk8.6'

if sys.platform=='win32':
    base = "Win32GUI"


setup(  name = 'cmd',
        description = "Created by Rohit Anand",
        options = {"build_exe":{"packages":['os.environ','tkinter.messagebox','tkinter.Tk'],"include_files":[r"C:\Users\rrohi\AppData\Local\Programs\Python\Python37-32\consol.ico",r"C:\Users\rrohi\AppData\Local\Programs\Python\Python37-32\DLLs\tcl86t.dll", r"C:\Users\rrohi\AppData\Local\Programs\Python\Python37-32\DLLs\tk86t.dll"]}},
        version="1.0",
        executables=[Executable("Prank(GUI).py", base=base)])

