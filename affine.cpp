#include<bits/stdc++.h>
using namespace std;

//Key values of a and b
int a,b;

//Encryption
string encryptMessage(string msg)
{

	string cipher = "";
	for (int i = 0; i < msg.length(); i++)
	{
		
		if(msg[i]!=' ')
		
			cipher = cipher +(char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
		else
			cipher += msg[i];	
	}
	return cipher;
}

//Decryption
string decryptCipher(string cipher)
{
	string msg = "";
	int a_inv = 0;
	int flag = 0;
	
	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;
		
		if (flag == 1)
		{
			a_inv = i;
		}
	}
	for (int i = 0; i < cipher.length(); i++)
	{
		if(cipher[i]!=' ')
			msg = msg +
					(char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
		else
			msg += cipher[i];
	}

	return msg;
}


int main()
{
	string msg;
	
	cout<<"Enter the plain text(message to be encrypted)"<<endl;
	cin>>msg;
	cout<<"Enter the the key vaues a and b, enter a such that it is relatively prime to 26"<<endl;
	cin>>a>>b;
	
	string cipherText = encryptMessage(msg);
	cout << "Encrypted Message is : " << cipherText<<endl;
	
	cout << "Decrypted Message is: " << decryptCipher(cipherText);

	return 0;
}
