#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

/*blueprint for the format of each line in the input .csv document*/
struct dataFormat{	
	char id[6];
	char name[30];
	char city[20];
	char sport[30];
	char event[20];
	char noc[3];
};

/*this function prevents unwanted characters from being written in the output file*/
bool cleanData(char character){

   if(character=='(' or character==')' or character=='-'){
	return true;  
   }
   else{
        return false;
   }
}

/*this function reads the input file and writes it's content on a new binary file after */
void newBINARYfile(){
	
	ifstream inputFile ("../inputFiles/data_athlete_event.csv");
	ofstream outputFile("../output/BinaryFile.bin");

    /*conjunto de variaveis auxiliares para guardar informacoes e 
    controlar campo de leitura em cada linha. Sao zeradas periodicamente 
    dentro do código */
	int characternum = 0;
	unsigned commaCounter =0, i=0, j=0;
	string line;
	char info[30];
    char character;
	dataFormat temporarySave;
	
	

	try{
		inputFile.open("../input/data_athlete_event.csv");
		if(inputFile){
			cout<< "Iniciando conversao" << endl;
			
			/*ignores the first line, since it doesnt carry relevant data*/
			getline(inputFile,line); 

			while(getline(inputFile,line)){
				commaCounter =0;
				i=0;
				j=0;
				cout<< line << endl;
				
				while(i<line.size()){	
						
					character = line[i];
					bool unwantedCharacter = cleanData(character);
	
					if(unwantedCharacter==true){
						i++;
					}
					else if(line[i]==','){
	
						if(line[i+1]==' '){
							characternum++;
							info[j]=line[i];
							i++;
						}
						else{                    
							commaCounter++;
							int k;
							
												
							/*the commaCounter's job is to inform which field of the dataFormat 
							the program is currently dealing with*/
							switch(commaCounter){
								case 1:
									for(k=0; k<characternum;k++){
										temporarySave.id[k]=info[k];
									}
									if(outputFile){
										outputFile.write((char*)(&temporarySave.id),sizeof(dataFormat));
									}
									else{
										throw 102;
									}
									break;  
								case 2:
									for(k=0; k<characternum;k++){
										temporarySave.name[k]=info[k];
									}
									if(outputFile){
										outputFile.write((char*)(&temporarySave.name),sizeof(dataFormat));
									}
									else{
										throw 102;
									}
									break;
								case 3:
									for(k=0; k<characternum;k++){
										temporarySave.city[k]=info[k];
									}							
									if(outputFile){
										outputFile.write((char*)(&temporarySave.city),sizeof(dataFormat));
									}
									else{
										throw 102;
									}
									break;
								case 4:
									for(k=0; k<characternum;k++){
										temporarySave.sport[k]=info[k];
									}
	
									if(outputFile){
										outputFile.write((char*)(&temporarySave.sport),sizeof(dataFormat));
									}
									else{
										throw 102;
									}
									break;
								case 5:
									for(k=0; k<characternum;k++){
									temporarySave.event[k]=info[k];
									}
	
								
									if(outputFile){
										outputFile.write((char*)(&temporarySave.event),sizeof(dataFormat));
									}
									else{
										throw 102;
									}
									break;
								case 6:
									for(k=0; k<characternum;k++){
										temporarySave.noc[k]=info[k];
									}
	
									if(outputFile){
										outputFile.write((const char*)(&temporarySave.noc),sizeof(dataFormat));
									}
									else{
										throw 102;
									}							    
									break;
									default:
										throw 103;
							}

							j=0;
							characternum=0;			
						}	
					}
					info[j]=line[i];
					i++;
				}
			}	
			cout<< "Conversion concluded" << endl;
		}
		else{
			throw 101;
		}
	}
	catch(int error){
		switch(error){
			case 101:
				cout<< "Conversion Failed! The input file can't be opened." << endl;
				cout<< "Please, try again" << endl;
				break;
			case 102:
				cout<< "Conversion failed! An error occured while writing on the output file." <<endl;
				cout<< "Please, try again" << endl;
				break;
			case 103:
				cout<< "Process aborted! Unknow exemption error." << endl;
				cout<< "Check data integrity and thy again." << endl;
				break;
		}
	}

}


/*this function provides a small user interface and calls the necessary function to fulfill the user's request*/
void menu(int menuOption){

	switch(menuOption){
		case 1:
			cout<< "The program will end now. Goodbye!" <<endl;
			break;
		case 2:
			cout<<"Starting the treating and conversion of the file to binary(.bin). A new file will be created for the modifications. Please, wait until the processes is finished."<<endl;
			cout<<" All the files content will be shown on you screen while the process is executed."<<endl;
			newBINARYfile();
			break;
	}

}

int main(){

	int menuOption;

	/*this repetition structure manages the menu and part of the user interface*/
	while(menuOption!= 1){

		cout<<"MENU"<<endl;
		cout<<"Press 1 to end the program"<<endl;
		cout<<"Press 2 to treat the data and create a BINARY FILE"<<endl;
		
		cin>>menuOption;

		try{
			if(menuOption== 1 or menuOption== 2  or menuOption== 3 ){
				menu(menuOption);
			}
			else{
				throw 100;
			}	
		}
		catch(int error){
			cout<< "Invalid menu option, please try again with a valid number" <<endl;
		}
	}
	return 0;
}
