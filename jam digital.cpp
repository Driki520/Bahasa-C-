#include<cstdlib>
#include<iostream>
#include<windows.h>
#include<time.h>

using namespace std;

struct jam{
	int hh,mm,ss,ms;
};
class jam_digital{
	public:
		jam_digital(){
			cout<<"\t\t------>>> Program jam digital<<------"<<endl<<endl;
		}
			void input_auto();
			void running();
			private:
				jam hour;
				int z;
};
		void jam_digital::input_auto(){
			struct tm *Sys_T;
			time_t Tval;
			
			Tval = time(NULL);
			Sys_T = localtime (&Tval);
			hour.hh=Sys_T->tm_hour;
			hour.mm=Sys_T->tm_min;
			hour.ss=Sys_T->tm_sec;
			hour.ms==00;
			
		}
		void jam_digital::running(){
			while(hour.hh<=24){
				while(hour.mm<=59){
					while(hour.ss<=59){
						while(hour.ms<=10){
							hour.ms++;
							Sleep(71);
							system("cls");
							jam_digital();
							printf("\n\n\n\n\n\n\n\n\n\t\t\t\t %02d %02d %02d %02d\n",hour.hh,hour.mm,hour.ss,hour.ms);
						}
						hour.ms=0;
						hour.ss++;
					}
					hour.ss=0;
					hour.ss++;
				}
				hour.mm=0;
				hour.hh++;
				if(hour.hh==24)
				hour.hh=0;
			}
		}
		int main(){
			jam_digital run;
			
			run.input_auto();
			run.running();
			
			system("pause");
			
			return 0;
		}
