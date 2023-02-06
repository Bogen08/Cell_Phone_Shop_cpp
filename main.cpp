#include <iostream>
#include<string>
#include <vector>
#include <cmath>

using namespace std;

class Phone{
	string brandName;
	string modelName;
	string formFactor;
	int yearOfIssue;
	float screenSize;
	float price;
	
	public:
		Phone(){
		}
		void setInfo(string brandName,
			string modelName,
			string formFactor,
			int yearOfIssue,
			float screenSize,
			float price){
				
			this->brandName=brandName;
			this->modelName=modelName;
			this->formFactor=formFactor;
			this->yearOfIssue=yearOfIssue;
			this->screenSize=screenSize;
			this->price=price;
		}
		string getBrandName(){
			return this->brandName;
		}
		string getModelName(){
			return this->modelName;
		}
		string getFormFactor(){
			return this->formFactor;
		}
		int getYearOfIssue(){
			return  this->yearOfIssue;
		}
		float getScreenSize(){
			return  this->screenSize;
		}
		float getPrice(){
			return  this->price;
		}
		void displayInfo(){
			cout<<"Brand name: "<<this->brandName<<endl;
			cout<<"Model name: "<<this->modelName<<endl;
			cout<<"Form factor: "<<this->formFactor<<endl;
			cout<<"Year of issue: "<<this->yearOfIssue<<endl;
			cout<<"Screen size: "<<this->screenSize<<" "<<endl;
			cout<<"Price: "<<this->price<<endl;
		}
};

struct Counter{
	Counter(string name, int counter = 1){
		this->name=name;
		this->counter=counter;
	}
	string name;
	int counter;
};

int main(int argc, char** argv) {
	
	int userChoice;
	
	string s;
	
	Phone inputPhone;
	
	string inputBrandName;
	string inputModelName;
	string inputFormFactor;
	int inputYearOfIssue;
	float inputScreenSize;
	float inputPrice;
	bool reportExit;
	bool Found;
	
	int maxCount;
	int maxJ;
	
	vector<Phone> phoneStorage;
	vector<Counter> counterTool;
	
	
	while(true){
		system("cls");
		cout<<"Main menu"<<endl<<"- - - - - - -"<<endl;
		cout<<"1.Add a new phone"<<endl;
		cout<<"2.Delete a phone"<<endl;
		cout<<"3.Show reports"<<endl;
		cout<<"4.Exit application"<<endl;
		cout<<endl<<"Enter your choice: ";
		cin>>userChoice;
		getline(cin,s);
		
		switch(userChoice){
			case 1:
				system("cls");
				cout<<"Enter Brand name: ";
				getline(cin,inputBrandName);
				
				system("cls");
				cout<<"Enter Model name: ";
				getline(cin,inputModelName);
				
				system("cls");
				cout<<"Enter Form factor: ";
				getline(cin,inputFormFactor);
				
				system("cls");
				cout<<"Enter Year of issue: ";
				cin>>inputYearOfIssue;
				getline(cin,s);
				
				system("cls");
				cout<<"Enter Screen size: ";
				cin>>inputScreenSize;
				
				system("cls");
				cout<<"Enter Price: ";
				cin>>inputPrice;
				
				system("cls");
				
				inputPhone.setInfo(inputBrandName,inputModelName,inputFormFactor,inputYearOfIssue,inputScreenSize,inputPrice);
				phoneStorage.push_back(inputPhone);

				cout<<"Phone added to Storage under id: "<<phoneStorage.size()-1<<endl;
				system("pause");
				
				break;
			case 2:
				system("cls");
				for (int i=0;i<phoneStorage.size();i++) {
						cout<<"Phone Id: "<<i<<endl;
					    phoneStorage[i].displayInfo();
					    cout<<endl;
					}
				cout<<endl<<"Enter id of element to remove from storage: ";
				cin>>userChoice;
				getline(cin,s);
				phoneStorage.erase(phoneStorage.begin()+userChoice);
				
				break;
			case 3:
				reportExit=false;
				while(true){
					
					system("cls");
					cout<<"Reports"<<endl<<"- - - - - - -"<<endl;
					cout<<"1.Show all phones by the same brand"<<endl;
					cout<<"2.Show all phones of a given form factor and screen size"<<endl;
					cout<<"3.Show the name of the brand with the maximum quantity of the phones"<<endl;
					cout<<"4.Show TOP-3 screen sizes"<<endl;
					cout<<"5.Go back to the Main menu"<<endl;
					cout<<endl<<"Enter your choice: ";
					cin>>userChoice;
					getline(cin,s);
					
					switch(userChoice){
						case 1:
							system("cls");
							cout<<"Enter Brand name to search: ";
							getline(cin,inputBrandName);
							
							for (int i=0;i<phoneStorage.size();i++) {
								if(phoneStorage[i].getBrandName() == inputBrandName){
									cout<<"Phone Id: "<<i<<endl;
								    phoneStorage[i].displayInfo();
								    cout<<endl;
								}
							}
							system("pause");
							
							break;
						case 2:
							system("cls");
							cout<<"Enter Form factor to search: ";
							getline(cin,inputFormFactor);
							
							system("cls");
							cout<<"Enter Screen to search: ";
							cin>>inputScreenSize;
							
							for (int i=0;i<phoneStorage.size();i++) {
								if(phoneStorage[i].getFormFactor() == inputFormFactor && phoneStorage[i].getScreenSize() == inputScreenSize){
									cout<<"Phone Id: "<<i<<endl;
								    phoneStorage[i].displayInfo();
								    cout<<endl;
								}
							}
							system("pause");
							break;
						case 3:
							system("cls");
							
							counterTool.push_back(Counter(phoneStorage[0].getBrandName(),0));
							
							for (int i=0;i<phoneStorage.size();i++) {
								Found=false;
								
								for (int j=0;j<counterTool.size();j++) {
									if(phoneStorage[i].getBrandName() == counterTool[j].name){
										counterTool[j].counter++;
										Found=true;
									}
									
								}
								if(!Found){
									counterTool.push_back(Counter(phoneStorage[i].getBrandName()));
								}
							}
							maxCount=0;
							for (int j=0;j<counterTool.size();j++) {
									if(counterTool[j].counter>maxCount){
										maxCount=counterTool[j].counter;
										maxJ=j;
									}
								}
								
							cout<<"Brand name with maximum quantity of the phones: "<<counterTool[maxJ].name<<endl;
							cout<<"Ammount: "<<counterTool[maxJ].counter<<endl;
							counterTool.clear();
							system("pause");
							
							break;
						case 4:
							break;
						case 5:
							reportExit=true;
							break;
						default:
						cout<<"Invalid number selected, please try again."<<endl;
						system("pause");
					}
					
					if(reportExit)break;
				}
				
				break;
			case 4:
				cout<<endl<<"Goodbye"<<endl;
				return 0;
			default:
				cout<<"Invalid number selected, please try again."<<endl;
				system("pause");
		}
		cout<<endl<<userChoice;
	}
}
