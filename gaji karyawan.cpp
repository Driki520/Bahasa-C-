#include<iostream>

using namespace std;

int main(){
	int mk,gol,jum_anak,gatot;
	int gapok=8000000;
	cout<<"\t\tKeterangan Bonus Masa Kerja Karyawan";
	cout<<"\nMasa Kerja kurang dari 2 Tahun = RP.500.000";
	cout<<"\nMasa Kerja 2-3 Tahun = RP.1.000.000";
	cout<<"\nMasa Kerja 1 Tahun = RP.500.000\n";
	cout<<"\t\tKeterangan Bonus Jabatan Karyawan";
	cout<<"\nGolongan 1 = RP.1.000.000";
	cout<<"\nGolongan 2 = RP.2.000.000";
	cout<<"\nGolongan 3 = RP.5.000.000\n";
	cout<<"\t\tKeterangan Bonus Tunjangan Anak Karyawan";
	cout<<"\nJumlah Anak lebih dari 2 = RP.400.000";
	cout<<"\nJumlah anak kurang dari 2 = RP.200.000";
	cout<<endl<<endl;
	
	
	cout<<"Masukan masa kerja: "; cin>>mk;
	cout<<endl;
	cout<<"Masukan golongan: ";cin>>gol;
	cout<<endl;
	cout<<"Masukan jumlah anak: ";cin>>jum_anak;
	cout<<endl;
	if(mk>5){
		mk=2000000;
	}else if(mk>=2 && mk<5 ){
		mk=1000000;
	}else if(mk<2){
		mk=500000;
	}else{
		mk=0;
	}
	if(gol==1){
		gol=1000000;
	}else if(gol==2){
		gol=2000000;
	}else if(gol==3){
		gol=5000000;
	}else{
		gol=0;
	}
	if(jum_anak>=2){
		jum_anak=400000;
	}else if(jum_anak<2){
		jum_anak=200000;
	}else{
		jum_anak=0;
	}
	cout<<"Bonus masa kerja RP."<<mk<<endl;
	cout<<"Bonus golongan jabatan RP."<<gol<<endl;
	cout<<"Bonus tunjangan anak RP."<<jum_anak<<endl;
	gatot=gapok+mk+gol+jum_anak;
	cout<<"Gaji total RP."<<gatot<<endl;
	return 0;
}
