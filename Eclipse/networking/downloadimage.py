import urllib.request

url = 'https://www.python.org/static/img/python-logo.png'
urllib.request.urlretrieve(url, 'python.png')