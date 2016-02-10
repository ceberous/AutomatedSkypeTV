import serial
import sys
import subprocess
import time



try:
	ser = serial.Serial( '/dev/ttyACM0' , 9600 )
except:
	try:
		ser = serial.Serial( '/dev/ttyACM1' , 9600 )
	except:
		pass

recievedData = ""
testValue = "c"

# curl -X POST -k https://192.168.1.101:8443/api/v1/service/skype/call/start/identification? -d "token%3D4792%26value%3D%7B%22toskypename%22+%3A+%22collin.cerbus%22%7D"


while 1:

	recievedData = ser.readline()
	recievedData = str(recievedData)
	recievedData = recievedData.replace( " " , "" )
	recievedDate = recievedData.rstrip()
	
	x = recievedData[0]

	# print(recievedData)
	if x is testValue:

		#proc = subprocess.Popen( [ 'curl' , '-X' , 'POST' , '-k' , "192.168.1.101:8443/api/v1/service/skype/call/start/identification?" , '-d' , "token%3D4792%26value%3D%7B%22toskypename%22+%3A+%22collin.cerbus%22%7D"  ] , stdout=subprocess.PIPE , stderr = subprocess.PIPE )
		
		#subprocess.call("./runCommand.sh" , stdout=subprocess.PIPE )

		p1 = subprocess.Popen( "./runCommand.sh" , stdout=subprocess.PIPE )

		output = p1.communicate()
		output = str(output[0])
		outputString = ''.join(output)
		splitString = outputString.split("{")
		result = splitString[5]
		result = result.split(",")
		result = result[1]
		result = result.split(":")
		result = result[1]
		result = result[1:8]
		print(result)
		callOver = False
		
		if result == "success":

			while callOver == False:

				p2 = subprocess.Popen( "./runCheckCommand.sh" , stdout=subprocess.PIPE )
				output2 = p2.communicate()
				output2 = str(output2[0])
				outputString2 = ''.join(output2)
				splitString2 = outputString2.split(":")
				splitString2 = splitString2[1]
				splitString2 = splitString2[0:4]
				print(splitString2)
				if splitString2 == "true":
					callOver = False
					time.sleep(5)
				else:
					callOver = True
					ser.write('1')

		else:
			callOver = True
			ser.write('1')
		# print("would write 1")
		#ser.write('1')	 
		
