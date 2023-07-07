#!/usr/bin/env python
'''
	This program allows user to specify interface ip and port to listen on for providing xml-rpc service.

	As an example service, simple math library functions are implemented and made available for remote call.

	This server program handles incoming requests untill user wish stop the server program explicitly.

	By default, it listen on loopback and port 60000 only. Use flags with command line arguments to change interface and port.
'''
from SimpleXMLRPCServer import SimpleXMLRPCServer
import optparse, os, sys
import threading
import time
import xmlrpclib
globalStop = False

def parseOptions():
	parser = optparse.OptionParser()

	parser.add_option("-i", "--interface", 
                          dest = "ip_InterfaceLocal",
                          default = "-", 
                          help="Use mentioned interface of this system for communication.")
	parser.add_option("-p", "--port",
                          dest = "port_PortLocal",
                          default = "-",
                          help="Use mentioned port of this system for communication.") 
	(options, args) = parser.parse_args()
	return options

options = parseOptions()

if options.ip_InterfaceLocal=='-':
	options.ip_InterfaceLocal = '127.0.0.1'
if options.port_PortLocal=="-":
	options.port_PortLocal = 60000
 
# Create xml-rpc server
serverLocal = SimpleXMLRPCServer((options.ip_InterfaceLocal, int(options.port_PortLocal)))
serverLocal.register_introspection_functions()

# Register an instance; all the methods of the instance are 
# published as XML-RPC methods (in this case, just 'div').
class MyMathClass:
    def add(self, x, y):
	return x+y
    def sub(self, x, y):
	return x-y
    def mul(self, x, y):
	return x*y
    def div(self, x, y):
        return float(x/y)

serverLocal.register_instance(MyMathClass())

print '****************** THIS IS SERVER PROGRAM ******************'
print 'Listening on %s:%d ' % (options.ip_InterfaceLocal, int(options.port_PortLocal))

print '************* PROVIDING XML-RPC SERVICES *******************'
print serverLocal.system_listMethods()
print '************************************************************'

class srvr(threading.Thread):
	def __init__(self):
		threading.Thread.__init__(self)
	def run(self):
		global globalStop	
		while not globalStop:
			serverLocal.handle_request()
		serverLocal.server_close()

#Start a thread which handles incoming xml-rpc requests.
s=srvr()
s.start()


#The following loop, stops the service when user enters 'stop' keyword.
while(1):
	print 'Enter \'stop\' to stop providing service.'
	action = sys.stdin.readline()
	if action.strip() == "stop":
		globalStop = True
		if s.isAlive():
			print 'Wait till last request is handled, if any.'
			time.sleep(10)
			if s.isAlive():
				if(options.ip_InterfaceLocal == ''):
					options.ip_InterfaceLocal = '127.0.0.1'
				xml_rpc_string = "http://%s:%d" %(options.ip_InterfaceLocal, int(options.port_PortLocal))
				s = xmlrpclib.Server(xml_rpc_string)
				s.system.listMethods()
		print 'bye'
		break;


print  'successfully exited'
