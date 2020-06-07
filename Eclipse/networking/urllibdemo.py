import urllib.request

try:
    url = urllib.request.urlopen("https://www.puython.org/")
    content = url.read()
    url.close()
except urllib.error.URLError: #,urllib.error.HTTPError
    print("Requested web page not found")
    exit()
    
f = open('downloadedpage.html','wb')
f.write(content)
f.close()