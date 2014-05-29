__author__ = 'Mark'


import tweepy
import serial
import time

##Authenticate with Twitter API
#api = tweepy.Api(consumer_key='IeHQABWkQ3fbJQCb4VpUmw', consumer_secret='LNxvg5rqHLDmdYGOAE8ZLPuCic2Hpvbq3hTpdkmo', access_token_key='984985916-5sFNoBNTjDEupoL5PSPR9g09WCoHLaGVBfXmHxkU', access_token_secret='WWFATp6cPpULpfMTxLvMkWxcyH7SQQLLX5ToSJSCcSk')

consumer_key="IeHQABWkQ3fbJQCb4VpUmw"
consumer_secret="LNxvg5rqHLDmdYGOAE8ZLPuCic2Hpvbq3hTpdkmo"

# The access tokens can be found on your applications's Details
# page located at https://dev.twitter.com/apps (located
# under "Your access token")
access_token="984985916-2NXZ4QNpj9LuYWlXa9eWdIKNZ9XMmYgYNkSrXVIY"
access_token_secret="4PuNDmHOI3X0B29SoCZNxwhiMeDKfHB7MTTxdPXt4"

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

##Configure Serial Port
arduino = serial.Serial('COM3', 9600)


while 1:  ##Infinite Loop
    status = arduino.readline() ##Wait for new line to come across Serial
    api.update_status(status) ##Post message to Twitter
    print status
    time.sleep(3600) ##Wait 3600 seconds
    del status	##Clear status


arduino.close()