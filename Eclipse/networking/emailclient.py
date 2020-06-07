import smtplib
from email.mime.text import MIMEText
import getpass
body='This is a test email. How are you?'

msg = MIMEText(body)
msg['From'] = 'abhi.pccs@gmail.com'
msg['To'] = 'abhi.pccs@gmail.com'
msg['Subject'] = 'Hello'

try:
    server = smtplib.SMTP("smtp.gmail.com",587)
except smtplib.SMTPConnectError as obj:
    print('Failed to connect server', obj)
    print()
else:
    print('Able to connect to Gmail server')
    try:
        server.starttls()
    except smtplib.SMTPException as objc:
        print('Secured server connection failed:',objc)
        print()
    else:
        print('Able to establish secured connection')
        try:
            username = input('Enter gmail id:')
            password = getpass.getpass('Please enter your password: ')
            server.login(username,password)
        except smtplib.SMTPException as objc:
            print('Login failed',objc)
            print()
        else:
            print('Able to login to account')
            try:
                server.send_message(msg)
            except smtplib.SMTPException as obj:
                print("Authentication failed.", obj)
            else:
                print('Main Sent')
finally:        
    server.quit()
