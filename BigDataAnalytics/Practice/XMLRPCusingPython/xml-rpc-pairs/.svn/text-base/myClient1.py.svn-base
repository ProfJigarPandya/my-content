#!/usr/bin/env python
'''
	This program works as a client program for myServer1.py

	Again, it allows to get service from customized destination interface and destination port. 
        Which local interface and port, this program may be using for communication is irrelevant. 

	Obviously, server program must be listening on that interface and port and accessible by this client for communication. 
                                                             Or some port forwarding is required to be setup for communication.

	This program just tries one of the service by myServer1.py xml-rpc server.
'''

from SimpleXMLRPCServer import SimpleXMLRPCServer
import optparse, os, sys
import xmlrpclib

def parseOptions():
        parser = optparse.OptionParser()

        parser.add_option("-i", "--interface",
                          dest = "ip_InterfaceDestination",
                          default = "-",
                          help="Use mentioned interface of destination system for communication.")
        parser.add_option("-p", "--port",
                          dest = "port_PortDestination",
                          default = "-",
                          help="Use mentioned port of destination system for communication.")
        (options, args) = parser.parse_args()
        return options

options = parseOptions()

if options.ip_InterfaceDestination=='-':
        options.ip_InterfaceDestination = '127.0.0.1'

if options.port_PortDestination=="-":
        options.port_PortDestination = 60000

print '****************** THIS IS CLIENT PROGRAM ******************'
print 'Communicating to  %s:%d' % (options.ip_InterfaceDestination, int(options.port_PortDestination))
print '************* REQUESTING XML-RPC SERVICES *******************'
xml_rpc_string = "http://%s:%d" %(options.ip_InterfaceDestination, int(options.port_PortDestination))
s = xmlrpclib.Server(xml_rpc_string)
print 'List of available services on destination server program:'
print s.system.listMethods()
print '************************************************************'

print 'Testing \'add\' method'

print 'Enter Operand1'
number1 = sys.stdin.readline()
print 'Enter Operand2'
number2 = sys.stdin.readline()
res = s.add(float(number1), float(number2))
print 'Result of %s + %s by destination \'add\' method is %f ' % (number1.strip(), number2.strip(),res)

#The communication is closed immediately after program termination.

print 'Program terminated successfully.'
