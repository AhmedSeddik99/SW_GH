import os
import re
import random

###########################           Variables           ############################

verilog_keywords = ['always', 'and', 'assign', 'automatic', 'begin', 'buf', 'bufif0', 'bufif1', 'case', 'casex', 'casez', 'cell',
    'cmos', 'config', 'deassign', 'default', 'defparam', 'design', 'disable', 'edge', 'else', 'end', 'endcase', 'endconfig',
    'endfunction', 'endgenerate', 'endmodule', 'endprimitive', 'endspecify', 'endtable', 'endtask', 'event', 'for', 'force', 'forever', 'fork',
    'function', 'generate', 'genvar', 'highz0', 'highz1', 'if', 'ifnone', 'incdir', 'include', 'initial', 'inout', 'input',
    'instance', 'integer', 'join', 'larger', 'liblist', 'library', 'localparam', 'macromodule', 'medium', 'module', 'nand', 'negedge',
    'nmos', 'nor', 'noshow-cancelled', 'not', 'notif0', 'notif1', 'or', 'output', 'parameter', 'pmos', 'posedge', 'primitive',
    'pull0', 'pull1', 'pullup', 'pulldown', 'pulsestyle_ondetect', 'pulsestyle_onevent', 'rcmos', 'real','realtime', 'reg','release', 
    'repeat', 'rnmos', 'rpmos', 'rtran', 'rtranif0', 'rtranif1', 'scalared', 'show-cancelled', 'signed','small', 'specify', 'specpa',
    'strong0', 'strong1', 'supply0', 'supply1', 'table', 'task', 'time', 'tran', 'tranif0', 'tranif1', 'tri', 'tri0', 'tri1', 'triand',
    'trior', 'trireg', 'use', 'vectored', 'wait', 'wand', 'weak0','weak1', 'while', 'wire', 'wor', 'xnor', 'xor']


parameters = {}             # Key -> Parameter Name, Value -> Parameter Width
inputs = []                 # List of Input Names
in_widths = []              # List of Input Widths
in_widths_num = []        # List of Input Widths as numbers only
outputs = {}                # Key -> Output Name, Value -> Output Type
out_widths = []             # List of Output Widths
out_widths_num = []         # List of Output Widths as numbers only
names_used = []

c = 0
ss = 0

#__________________________________________________________________________________________________________________________#      



############################           Functions           ############################

def Check_Name(Chk_Name):
    while True:
        name = input(f"Enter the name of the {Chk_Name} : ")    
        name = name.lower()   
        if(name in names_used):
            print(f"Name '{name}' is already used. Please choose another name.")
        elif(name in verilog_keywords):
            print(f"Name of the {Chk_Name} cannot be a keyword. Please enter a different name.")
        elif(re.search(r'^\d', name)):
            print(f"Name of the {Chk_Name} cannot start with a digit. Please enter a different name.")
        elif(re.search(r'\W', name)):
            print(f"Name of the {Chk_Name} cannot contain neither special characters nor space. Please enter a different name.")
        else:
            print(f"Name of the {Chk_Name}: {name}")
            break
        
    names_used.append(name)
    return name  
#-----------------------------------------------------------------------                          
                                        
        


def Check_Number(Chk_Num):
    while True:           
        try:
            num = int(input(f"Enter the {Chk_Num} : "))
            q = 2/num
            if(num < 0):
                int("num")
        except ValueError: 
            print(f"Invalid {Chk_Num}. Please enter an integer.")
        except ZeroDivisionError: 
            print(f"Invalid {Chk_Num}. Please enter a non-zero integer.")
        else:
            print(f"{Chk_Num} = {num}")
            break
    
    return num
#----------------------------------------------------------------------------                           




def Check_Parameter(input_name):
    while True:
            try:
                input_width = input(f"Enter the Parameter Name: ")
                parameters[input_width]
            except KeyError:
                print(f"Parameter not found. Please enter a Valid Parameter Name.")
            else:            
                print(f"Width of {input_name} = {input_width}")
                break
            
    return input_width  
#----------------------------------------------------------------------------                           



def Check_Reply(string, reply1, reply2):
    while True:
        reply = input(f"{string}")   
        reply = reply.lower()          
        if((reply == reply1) | (reply == reply2)):
            break
        else:
            print(f"Please, Enter {reply1} or {reply2}")
                
    return reply
       



#__________________________________________________________________________________________________________________________#      


######          Module Name         ###### 
module_name = Check_Name("Module")        
#----------------------------------------#



######          Parameters         ###### 
chk_par = Check_Reply("Are there Parameters ?\n (y/n): ", 'y', 'n')
if(chk_par == 'y'):
    parameter_num = Check_Number("Number of Parameters")        
    
    for i in range(0, parameter_num):
        parameter_name = Check_Name(f"Parameter number {i+1}")
        parameter_width = Check_Number(f"{parameter_name}")
        parameters.update({parameter_name:parameter_width})

print(parameters.items())
#--------------------------------------------------------------------------#        

######          Check Circuit Type          ######
is_seq = Check_Reply("Is the design Sequential ?\n (y/n): ", 'y', 'n')

if(is_seq == 'y'):
    clkedge = Check_Reply("Triggered with Positive or Negative Edge of the Clock ?\n (pos/neg): ", "pos", "neg")
    is_sync = Check_Reply("The Reset is Synchronous or Asynchronous ?\n (sync/async): ", "sync", "async")
    rstedge = Check_Reply("The Reset is Active High or Low ?\n (high/low): ", "high", "low")
    clk_period = Check_Number("Clock Period")
    
    if(rstedge == "high"):
        rstedge = "pos"
    else:
        rstedge = "neg"
#--------------------------------------------------------------------------#


######          Inputs          ######
if(is_seq == 'y'):
    in_num = Check_Number("Number of Inputs Including clk & rst")
    inputs.append ("clk")
    in_widths.append(1)
    inputs.append("rst")
    in_widths.append(1)
    c = 2
else:
    in_num = Check_Number("Number of Inputs")
    
for i in range(c, in_num):
    input_name = Check_Name(f"Input number {i+1}")
    inputs.append(input_name)
    if(chk_par == 'y'):
        is_par = Check_Reply("Is the Width of this Input Parameterized ?\n (y/n): ", 'y', 'n')
        if(is_par == 'y'):
            input_width = Check_Parameter(input_name)
            wd = parameters[input_width]
        else:                                                       # if not parameterized input
            input_width = Check_Number(f"Width of {input_name}")
            wd = input_width
    else:                                                           # if not parameterized module 
        input_width = Check_Number(f"Width of {input_name}")
        wd = input_width
        
    in_widths.append(input_width)
    in_widths_num.append(wd)
    
print(inputs)
print(in_widths)    
# --------------------------------------------------------------------------#        
  


######          Outputs          ######
out_num = Check_Number("Number of Outputs")
for i in range(0, out_num):
    output_name = Check_Name(f"Output number {i+1}")
    output_type = Check_Reply(f"{output_name} Type is reg or wire ?\n (reg/wire): ", "reg", "wire")
    outputs.update({output_name : output_type})
    if(chk_par == 'y'):
        is_par = Check_Reply("Is the Width of this Output Parameterized ?\n (y/n): ", 'y', 'n')
        if(is_par == 'y'):
            output_width = Check_Parameter(output_name)
            wd = parameters[output_width]
        else:                                                               # if not parameterized output
            output_width = Check_Number(f"Width of {output_name}")
            wd = output_width
    else:                                                                   # if not parameterized module 
        output_width = Check_Number(f"Width of {output_name}")
        wd = output_width
    
    out_widths.append(output_width)
    out_widths_num.append(wd)
    
print(outputs.items())
print(out_widths)    
#--------------------------------------------------------------------------#  
 
#__________________________________________________________________________________________________________________________#   
 
 
 
############################           Files Creation           ############################

# Examples
# module_name = "example"
# chk_par = 1
# parameters = {"In_Width":8, "Out_Width":8}     
# is_seq = 'y'
# clkedge = "pos"
# is_sync = "sync"
# rstedge = "neg"
# in_num = 4
# inputs = ['clk', 'rst', 'IN1', 'IN2']         
# in_widths = [1, 1, 6, 'In_Width']      
# outputs = {"OUT1": "reg", "OUT2": "wire", "OUT3": "reg"}      
# out_num = 0  
# out_widths = [1, 3, 'Out_Width']     

# clk_period = 20
#===========================================



Fdesign_w = open(f"{module_name}.v", 'w') 
Ftb_w = open(f"{module_name}_tb.v", 'w') 



#-*-*-*-*-*-*-*- Start of Module Declaration -*-*-*-*-*-*-*-*-#

Fdesign_w.write(f"module {module_name} ")                             
Ftb_w.write(f"module {module_name}_tb;\n\n\n")     
if(is_seq == 'y'):
    Ftb_w.write(f"\tparameter clk_period = {clk_period};\n")                       

if(chk_par == 'y'):
    Fdesign_w.write(f"#(parameter ")
    for key in parameters:
        Fdesign_w.write(f"{key} = {parameters[key]}, ")
        Ftb_w.write(f"\tparameter {key}_tb = {parameters[key]};\n")

    
        
    
    Fdesign_w.close()
    
    Fdesign_r = open(f"{module_name}.v", 'r') 
    line = Fdesign_r.read()
    Fdesign_r.close()
                                                            
    # print(line)                                                 # Before Edit         
    line = re.sub(r',\s$', ') ', line)                          # search for ',' after last parameter then replace with ')'
    # print(line)                                                 # Before Edit

    Fdesign_w = open(f"{module_name}.v", 'w') 
    Fdesign_w.write(line)

Fdesign_w.write(f"(\n")           

#-*-*-*-*-*-*-*- End of Module Declaration -*-*-*-*-*-*-*-*-#


Ftb_w.write(f"\n\n")           


#-*-*-*-*-*-*-*- Start of Ports Declaration -*-*-*-*-*-*-*-*-#
## Inputs
for i in range(0, in_num):                                      
    if(type(in_widths[i]) == str):         ## Parameterized 
        Fdesign_w.write(f"input \t wire \t [{in_widths[i]}-1:0] \t\t\t {inputs[i]},\n")  
        Ftb_w.write(f"\treg \t [{in_widths[i]}-1:0] \t\t\t {inputs[i]}_tb;\n")                                
    elif(in_widths[i] != 1):               ## Not Parameterized      
        Fdesign_w.write(f"input \t wire \t [{in_widths[i]-1}:0] \t\t\t\t {inputs[i]},\n")              
        Ftb_w.write(f"\treg \t [{in_widths[i]-1}:0] \t\t\t\t {inputs[i]}_tb;\n")              
    else:                                 ## 1 bit        
        Fdesign_w.write(f"input \t wire \t\t\t\t\t\t {inputs[i]},\n")    
        Ftb_w.write(f"\treg \t\t\t\t\t\t {inputs[i]}_tb;\n")    
        
        
## Outputs        
for i, key in enumerate(outputs):                                      
    if(type(out_widths[i]) == str):             ## Parameterized 
        Fdesign_w.write(f"output \t {outputs[key]} \t [{out_widths[i]}-1:0] \t\t\t {key},\n")                                
        Ftb_w.write(f"\twire \t [{out_widths[i]}-1:0] \t\t\t {key}_tb;\n")                                
    elif(out_widths[i] != 1):                   ## Not Parameterized
        Fdesign_w.write(f"output \t {outputs[key]} \t [{out_widths[i]-1}:0] \t\t\t\t {key},\n")              
        Ftb_w.write(f"\twire \t [{out_widths[i]-1}:0] \t\t\t\t {key}_tb;\n")              
    else:                                       ## 1 bit
        Fdesign_w.write(f"output \t {outputs[key]} \t\t\t\t\t\t {key},\n")    
        Ftb_w.write(f"\twire \t\t\t\t\t\t {key}_tb;\n")    
        
        
 
  
### Removing last ',' and closing ( ) of Ports          
Fdesign_w.close()
    
Fdesign_r = open(f"{module_name}.v", 'r') 
lines = Fdesign_r.read()                                                        
Fdesign_r.close()

new_lines = re.sub(r',\s$', '\n);', lines)                          # search for ',' after last out then replace with ')'

Fdesign_w = open(f"{module_name}.v", 'w')    
Fdesign_w.write(new_lines)


#-*-*-*-*-*-*-*- End of Ports Declaration -*-*-*-*-*-*-*-*-#        


Fdesign_w.write(f"\n\n\n")
Ftb_w.write(f"\n\n\n")


#-*-*-*-*-*-*-*- Start of Internal Signals Declaration -*-*-*-*-*-*-*-*-#      

Fdesign_w.write(f"// internal signals \n")
Fdesign_w.write(f"wire \t sig1;\n")
Fdesign_w.write(f"reg \t sig2;\n")
Fdesign_w.write(f"\n\n\n\n")
  
#-*-*-*-*-*-*-*- End of Internal Signals Declaration -*-*-*-*-*-*-*-*-#        



#-*-*-*-*-*-*-*- Start of Always Blocks Declaration -*-*-*-*-*-*-*-*-#        

# Combinational
Fdesign_w.write(f"always @ (*) begin \n")
Fdesign_w.write(f"\tif (/* condition */) begin \n \t // body \n\tend \n")
Fdesign_w.write(f"\telse if (/* condition */) begin \n \t // body \n\tend \n")
Fdesign_w.write(f"\telse begin \n \t // body \n\tend\n")
Fdesign_w.write(f"end\n")

Fdesign_w.write(f"\n\n\n")

# Sequential
if(is_seq == 'y'):
    if(is_sync == 'async'):
        Fdesign_w.write(f"always @ ({clkedge}edge clk) begin \n")
    else:
        Fdesign_w.write(f"always @ ({clkedge}edge clk or {rstedge}edge rst) begin \n")
    
    if(rstedge == "pos"):    
        Fdesign_w.write(f"\tif (rst) begin \n \t // body \n\tend \n")
    else:
        Fdesign_w.write(f"\tif (!rst) begin \n \t // body \n\tend \n")
    
        
    Fdesign_w.write(f"\telse if (/* condition */) begin \n \t // body \n\tend \n")
    Fdesign_w.write(f"\telse begin \n \t // body \n\tend\n")
    Fdesign_w.write(f"end\n")

#-*-*-*-*-*-*-*- End of Always Blocks Declaration -*-*-*-*-*-*-*-*-#        

#-*-*-*-*-*-*-*- Start of DUT Declaration -*-*-*-*-*-*-*-*-#  

Ftb_w.write(f"{module_name} DUT (\n")

for inp in inputs:
    Ftb_w.write(f"\t.{inp}({inp}_tb),\n")                   
     
for out in outputs:
    Ftb_w.write(f"\t.{out}({out}_tb),\n")                             


### Removing last ',' and closing ( ) of Dut          
Ftb_w.close()
    
Ftb_r = open(f"{module_name}_tb.v", 'r') 
lines = Ftb_r.read()                                                        
Ftb_r.close()

new_lines = re.sub(r',\s$', '\n);', lines)                          # search for ',' after last out then replace with ')'

Ftb_w = open(f"{module_name}_tb.v", 'w')    
Ftb_w.write(new_lines)        

      
#-*-*-*-*-*-*-*- End of DUT Declaration -*-*-*-*-*-*-*-*-#        


Ftb_w.write(f"\n\n\n\n")


#-*-*-*-*-*-*-*- Start of Clock Generation -*-*-*-*-*-*-*-*-#  
if(is_seq == 'y'):
    Ftb_w.write(f"always # (clk_period/2) clk_tb = !clk_tb;\n")

#-*-*-*-*-*-*-*- End of Clock Generation -*-*-*-*-*-*-*-*-# 


Ftb_w.write(f"\n\n\n")


#-*-*-*-*-*-*-*- Start of Initial Block Declaration -*-*-*-*-*-*-*-*-#  

Ftb_w.write(f"initial begin \n")

Ftb_w.write(f"\t$dumpfile({module_name}.vcd); \n")
Ftb_w.write(f"\t$dumpvars; \n")

Ftb_w.write(f"\tinitialize();\n")
if(is_seq == 'y'):
    Ftb_w.write(f"\treset();\n")

Ftb_w.write(f"\t\n\n")

ss = 0
Ftb_w.write(f"\t// test case1\n")
if(is_seq == 'y'):
    for inp in inputs[2:]:
        Ftb_w.write(f"\t{inp}_tb = 'd{random.randrange(0, (2**in_widths_num[ss])-1)};\n")       
        ss +=1
else:
    for inp in inputs:
        Ftb_w.write(f"\t{inp}_tb = 'd{random.randrange(0, (2**in_widths_num[ss])-1)};\n")               
        ss +=1

Ftb_w.write(f"\t\n")

if(is_seq == 'y'):
    Ftb_w.write(f"\t#(clk_period)\n")
else:
    Ftb_w.write(f"\t#20\n")
    
Ftb_w.write(f"\t\n")

Ftb_w.write(f"\t// test case2\n")

ss = 0
if(is_seq == 'y'):
    for inp in inputs[2:]:
        Ftb_w.write(f"\t{inp}_tb = 'd{random.randrange(0, (2**in_widths_num[ss])-1)};\n")       
        ss +=1
else:
    for inp in inputs:
        Ftb_w.write(f"\t{inp}_tb = 'd{random.randrange(0, (2**in_widths_num[ss])-1)};\n")       
        ss +=1

Ftb_w.write(f"\t\n\n")



Ftb_w.write(f"\t#200\n")
Ftb_w.write(f"\tstop;\n")
Ftb_w.write(f"end\n")
      
#-*-*-*-*-*-*-*- End of Initial Block Declaration -*-*-*-*-*-*-*-*-#  

Ftb_w.write("\n\n\n\n")

#-*-*-*-*-*-*-*- Start of Functions/Tasks Declaration -*-*-*-*-*-*-*-*-#  

## Initialize Task
Ftb_w.write(f"//initialize Task \n")
Ftb_w.write(f"task initialize; \n")
Ftb_w.write(f"\tbegin \n")

if(is_seq == 'y'):
    Ftb_w.write(f"\t\tclk_tb = 1'b0;\n")
    if(rstedge == "pos"):
        Ftb_w.write(f"\t\trst_tb = 1'b0;\n")
    else:
        Ftb_w.write(f"\t\trst_tb = 1'b1;\n")
        
    for inp in inputs[2:]:
        Ftb_w.write(f"\t\t{inp}_tb = 'b0;\n")                   
else:
    for inp in inputs:
        Ftb_w.write(f"\t\t{inp}_tb = 'b0;\n")        
        
     
Ftb_w.write(f"\tend \n")
Ftb_w.write(f"endtask\n")
            
            
Ftb_w.write(f"\n\n\n\n")
      
      
## Reset Task
if(is_seq == 'y'):
    Ftb_w.write(f"//reset Task \n")
    Ftb_w.write(f"task reset; \n")
    Ftb_w.write(f"\tbegin \n")

    if(rstedge == "pos"):
        Ftb_w.write(f"\t\t#(clkperiod)\n")
        Ftb_w.write(f"\t\trst_tb = 1'b1;\t\t\t // reset is activated \n")                
        Ftb_w.write(f"\t\t#(clkperiod)\n")
        Ftb_w.write(f"\t\trst_tb = 1'b0;\t\t\t // reset is dectivated\n")                  
        Ftb_w.write(f"\t\t#(clkperiod)\n")
    else:
        Ftb_w.write(f"\t\t#(clkperiod)\n")
        Ftb_w.write(f"\t\trst_tb = 1'b0;\t\t\t // reset is activated \n")                
        Ftb_w.write(f"\t\t#(clkperiod)\n")
        Ftb_w.write(f"\t\trst_tb = 1'b1;\t\t\t // reset is dectivated\n")                  
        Ftb_w.write(f"\t\t#(clkperiod)\n")
        
    Ftb_w.write(f"\tend \n")
    Ftb_w.write(f"endtask\n")      
      
      
#-*-*-*-*-*-*-*- End of Functions/Tasks Declaration -*-*-*-*-*-*-*-*-# 


Fdesign_w.write(f"\n\n\n")
Fdesign_w.write(f"endmodule")


Ftb_w.write(f"\n\n\n")
Ftb_w.write(f"endmodule")



Fdesign_w.close()
Ftb_w.close()
 
 
 
 
#__________________________________________________________________________________________________________________________#