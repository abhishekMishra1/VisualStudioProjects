class InvalidPasswordException(Exception):
    def __init__(self, message):
        self.errorMsg = message

try:
    password = input('Enter password:')
    if len(password) < 8:
        raise InvalidPasswordException("Length issue")
    elif ' ' in password:
        raise InvalidPasswordException('Space not allowed')
    else:
        print('Entered correct password')
except InvalidPasswordException as obj:
        print(obj)
        
'''
try:
    password = input('Enter password:')
    assert len(password) >=8, 'InvalidPasswordException: PLease provide password of at least 8 characters long'
    assert not(' ' in password), 'InvalidPasswordException: Please do not provide space in password'
except AssertionError as obj:
    print(obj)
else:
    print('Entered correct password')
'''