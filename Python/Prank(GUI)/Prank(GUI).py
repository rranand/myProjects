from tkinter import messagebox,Tk
from os import environ

'''
This Program is created by Rohit Anand.
'''

root=Tk()
root.wm_iconbitmap('consol.ico')
root.withdraw()
flag=messagebox.askquestion('This PC','Error while opening This PC. Do you want to fix this error?')

if flag=='yes':
    flag=messagebox.askquestion('Windows Defender','Unable to fix this error. Do you want to scan your PC?')
    
    if flag=='yes':
        flag=messagebox.askyesnocancel('Windows Defender','Alert! Virus Detected. Delete virus?')
        
        if flag==True:
            flag=messagebox.askretrycancel('Windows Defender','Unable to delete virus')
            
            if flag==True:
                flag=messagebox.askokcancel('Windows Defender','Virus is activated. Want to disable?')
                
                if flag==True:
                    flag=messagebox.askokcancel('Windows Defender','Deleting System32 folder. Want to stop?')
                    
                    if flag==True:
                        flag=messagebox.askyesnocancel('This PC','Virus is copying your files. Want to stop?')
                        
                        if flag==True:
                            flag=messagebox.askyesnocancel('This PC','Please Wait, uploading your files to server. Want to stop?')
                            
                            if flag==True:
                                flag=messagebox.showinfo('This PC', 'Files uploaded successfully. Could not stop')
                                string='Your computer '+str(environ['COMPUTERNAME'])+' is hacked.'
                                flag=messagebox.showwarning('This PC',string)
                                flag=messagebox.showinfo('Prank','Bhaiya Chutiya Banae Ho aap!!!')