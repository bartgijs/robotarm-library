# Custom robotarm library
Library for the robotarm that can be included in any PlatformIO project

## Usage
_Describe how to use the library here._

## Message protocol
When the library is running on the device, it listens for commands on the serial port. The messages that are sent to the library are based on the SSC-32U protocol, made by Lynxmotion. The accepted commands are described below in subheaders.

### Accepted joints
The joints are represented as a number. Below you can find what joint is represented by what number.
 1. SHOULDER_ROTATE
 2. SHOULDER_UP_DOWN / SHOULDER_UP_AND_DOWN
 3. ELBOW
 4. WRIST_ROTATE
 5. WRIST_UP_DOWN / WRIST_UP_AND_DOWN
 6. GRIPPER / GRIPPER CLOSE

### Move one or more joints
**Command structure**  
\# \<joint\> P \<pw\> _S \<spd\> T \<time\>_ \<cr\>  

**Explained structure**
 * **\#** : Static, message start
 * **\<joint/>** : The name of the joint, as described above
 * **P** : Static, starts the block that sets the new position
 * **\<pw\>** : New pulse width value
 * **S** : Static, starts the block for the speed. Only affects the joint it comes after. (optional)
 * **\<sp\>** : Speed in maximal change of microseconds (on the PWM signal) per second
 * **T** : Static, starts the block for the time. (optional)
 * **\<time\>** : This sets the minimal time the entire operation takes in milliseconds (all joints). When a single joint cannot reach the set point within the given time, it will arrive later.
 * **\<cr\>** : Carriage return, ends the command

### (Emergency) stop
**Command**  
STOP

**Details**  
Tries to immediately stop all movement. Movement that was started without a limit on speed cannot be stopped this way, as the microcontroller does not use feedback from the servos. The controller has to assume that the servo moves instantly, unless told otherwise.

### Set the offset on a servo from the middle
**Command structure**  
\# \<joint\> PO \<offset value\> \<cr\>

**Details**
This command can be used to correct for small mistakes in assembling the robotarm. The center of the servo will be offset by a max of 15 degrees. The data sent to this command should be in microseconds (us). When the device is turned off it forgets this setting.

### Query the status of the movement
**Command**  
Q \<cr\>  

**Details**
When the movement is complete, a single dot (.) is sent to the serial output. When the movement is not complete, a plus (+) is sent.

### Query the pulse width of a joint
**Command structure**  
QP \# \<joint\> \<cr\>  

**Details**
Writes the current position of the servo to the serial output. The output may not be accurate when the speed is set to the maximal speed.
The data is sent in ASCII format, where every decimal digit is represented by a new character.

## Installation
_Describe how to install the library in an existing project here._

## Functionality
_Describe what the library is capable of here._
