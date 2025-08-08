
from SimpleXMLRPCServer import SimpleXMLRPCServer

# Create server
server = SimpleXMLRPCServer(("10.19.0.115", 8000))
server.register_introspection_functions()

# Register pow() function; this will use the value of 
# pow.__name__ as the name, which is just 'pow'.
server.register_function(pow)

# Register a function under a different name
def adder_function(x,y):
    return x + y
server.register_function(adder_function, 'add')

# Register an instance; all the methods of the instance are 
# published as XML-RPC methods (in this case, just 'div').
class MyFuncs:
    def div(self, x, y): 
        return x // y
    
server.register_instance(MyFuncs())

# Run the server's main loop
server.serve_forever()
