# -*- coding: utf-8 -*-
"""
Created on Wed Sep 29 14:54:37 2021

"""
import smtplib
from email.mime.text import MIMEText
msg_from="2661351252@qq.com"
passwd="oueupeaiyqbtebea"
msg_to="57820048@qq.com"

subject = "2019144124 л����"
content = "������˽��IP��ַ��10.169.236.71������IP��ַ��172.68.133.82������У԰�������������˽��IP��ַ��10.128.66.194������IP��ַ��39.129.40.49"
msg = MIMEText(content)
msg['Subject'] = subject
msg['From']= msg_from
msg['To'] = msg_to
try:
    s = smtplib.SMTP_SSL("smtp.qq.com",465)
    s.login(msg_from,passwd)
    s.sendmail(msg_from,msg_to,msg.as_string())
    print("���ͳɹ�")
except Exception as e:
    print("����ʧ��",e)
finally:
    s.quit()