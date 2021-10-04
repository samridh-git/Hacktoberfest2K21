from requests import get
import ipapi

IP = input('Enter any IP here...')
data = ipapi.location(ip=IP, output='json')

print(data) # show's all the data about the given IP Address
