from tkinter import *
from tkinter import Tk,messagebox,Label,StringVar,Label,Entry
from smtplib import SMTP
import re

class login:

    def __init__(self,root):
        self.l1=Label(text='Welcome to SMTP Portal',font="15",justify='center').pack(fill=X,padx=20)
        self.t_username= Label(text='Enter your Email-id:',font='10').place(x=100,y=100)
        self.t_password= Label(text='Enter your password:',font='10').place(x=100,y=160)
        self.t_to= Label(text='Send to:',font='10').place(x=100,y=220)
        self.t_subject= Label(text='Subject:',font='10').place(x=100,y=280)
        self.t_message= Label(text='Enter your message:',font='10').place(x=100,y=340)
        
        username=StringVar()
        password=StringVar()
        toemail=StringVar()
        subject=StringVar()
        message=StringVar()
        
        self.e1=Entry(root,textvariable=username,font='10').place(x=350,y=100)
        self.e2=Entry(root,textvariable=password,font='10',show='*').place(x=350,y=160)
        self.e3=Entry(root,textvariable=toemail,font='10').place(x=350,y=220)
        self.e4=Entry(root,textvariable=subject,font='10').place(x=350,y=280)
        self.e5=Entry(root,textvariable=message,font='10').place(x=350,y=340)
        
        def reset():
            subject.set('')
            message.set('')
            toemail.set('')
        
        def send():
            flag=True
            try:
                connect=SMTP('smtp.gmail.com',587)
            except:
                msg=messagebox.showerror('No Internet','Chutiyae Internet is not working!!!')
                flag=False
            if flag==True:
                connect.ehlo()
                connect.starttls()
                try:
                    connect.login(str(username.get()),str(password.get()))
                except:
                    msg=messagebox.showerror('Wrong Credentials','Login/Password is wrong!!!')
                    flag=False
                if flag==True:
                    content='Subject: '+str(subject.get())+'\n\n'+str(message.get())
                    connect.sendmail(str(username.get()),str(toemail.get()),content)
                    connect.quit()
                    reset()
                    msg=messagebox.showinfo('Mail Sent','Mail Successfully Successfully!!!')
        
        def check():
            flag=True
            if bool(re.search('\w+@gmail.com',str(username.get())))!=True:
                msg=messagebox.showwarning('Incorrect email','Enter only Gmail email id')
                flag=False
            if bool(re.search('\w+@\w+\.\w+',str(toemail.get())))!=True:
                msg=messagebox.showwarning('Incorrect email','Enter correct recevier Email id ')
                flag=False
            if bool(re.search('\w+',str(subject.get())))!=True:
                msg=messagebox.showwarning('Incorrect subject','Subject is empty')
                flag=False
            if bool(re.search('\w+',str(password.get())))!=True:
                msg=messagebox.showwarning('Incorrect password','password is not entered')
                flag=False
            if bool(re.search('\w+',str(message.get())))!=True:
                msg=messagebox.showwarning('Incorrect Message','Message is not entered')
                flag=False
            
            if flag==True:
                send()
        
        self.but=Button(root,text='Send',width=5,font=11,command=check).place(x=320,y=390)
        self.copyright=Label(text='***Created by Rohit Anand***',font=8,justify='center').pack(side='bottom')
        

    
root=Tk()
root.geometry('720x560')
root.title('SMTP Portal')
root.wm_iconbitmap('icon.ico')
ob=login(root)
root.mainloop()