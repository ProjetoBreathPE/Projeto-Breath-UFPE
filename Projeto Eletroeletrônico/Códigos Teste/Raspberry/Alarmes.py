import RPi.GPIO as GPIO 
import time

GPIO.setmode(GPIO.BCM) #usando numeração GPIO
GPIO.setup(25,GPIO.OUT,initial = 0)
t = time.localtime()
current_time = time.strftime("%D:%H:%M:%S", t)
print(current_time)

GPIO.output(25,0)

#variáveis para simulação
PIP = 100
xmin = 5
xmax = 30

#Parâmetros dos pulsos de acordo com NBR 60601-1-8
#td1 + x deve ser MENOR ou IGUAL a td2 + y

#Alta prioridade
pulseWidth1 = 0.125 #largura de pulso
x = 0.1
var1 = 2*x+pulseWidth1
var2 = 1
interval1 = 2.5

#Média e baixa prioridade
pulseWidth2 = 0.125
y = 0.2
interval2 = 3    #media prioridade
interval3 = 16   #baixa prioridade


while(1):
    if(PIP >= xmin and PIP <= xmax):
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(var1)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(var2)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(var1)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(x)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth1)
        GPIO.output(25,0)
        time.sleep(interval1)
        
        
    if(PIP > xmax or PIP < xmin):
        GPIO.output(25,1)
        time.sleep(pulseWidth2)
        GPIO.output(25,0)
        time.sleep(y)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth2)
        GPIO.output(25,0)
        time.sleep(y)
        
        GPIO.output(25,1)
        time.sleep(pulseWidth2)
        GPIO.output(25,0)
        time.sleep(interval2)
        