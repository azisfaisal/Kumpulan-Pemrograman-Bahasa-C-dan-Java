#include "header.h"

int bonus(char no_pegawai[],char no_undian[],int gaji_pokok){
	
	int hasil = 0;
	
	//jika 2 digit pertama sama dengan 2 digit pertama di no undian
	if(no_pegawai[0]==no_undian[0] && no_pegawai[1]==no_undian[1]) hasil = hasil + ((5*gaji_pokok)/100);

	//jika 2 digit kedua sama dengan 2 digit kedua di no undian
	if(no_pegawai[2]==no_undian[2] && no_pegawai[3]==no_undian[3]) hasil = hasil + ((10*gaji_pokok)/100);
	
	//jika 2 digit ketiga sama dengan 2 digit ketiga di no undian
	if(no_pegawai[4]==no_undian[4] && no_pegawai[5]==no_undian[5]) hasil = hasil + ((15*gaji_pokok)/100);
	
	return hasil;
}

void createList(list *L){
	
	(*L).first = -1;
	int i;
	
	//proses menginisialisasi isi array
	for(i=0;i<n;i++) (*L).data[i].next = -2;
}

int countElement(list L){
	
	int hasil = 0;
	if(L.first != -1){			//list tidak kosong
		
		int elmt;
		elmt = L.first;			//inisialisasi
		
		while(elmt != -1){
			hasil++;						//proses
			elmt = L.data[elmt].next;		//iterasi
		}
		
	}
	
	return hasil;
	
}

int emptyElement(list L){
	
	int hasil = -1;
	
	if(countElement(L) < 10){
		
		int ketemu = 0;
		int i = 0;
		
		while(ketemu==0 && i<n){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}
			
			else i++;
		}
		
	}
	
	return hasil;
	
}

void addFirst(char nama[],char no_pegawai[],int gaji_pokok,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.no_pegawai, no_pegawai);
		(*L).data[baru].elmt.gaji_pokok = gaji_pokok;  
		(*L).data[baru].elmt.bonus_gaji = 0;  
		(*L).data[baru].elmt.total_gaji = 0;  
		
		if((*L).first == -1) (*L).data[baru].next = -1;		//jika list kosong
		else (*L).data[baru].next = (*L).first;				//jika list tidak kosong
		
		(*L).first = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addAfter(int prev,char nama[],char no_pegawai[],int gaji_pokok, list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.no_pegawai, no_pegawai);
		(*L).data[baru].elmt.gaji_pokok = gaji_pokok;
		(*L).data[baru].elmt.bonus_gaji = 0;  
		(*L).data[baru].elmt.total_gaji = 0;  
		
		if((*L).data[prev].next == -1) (*L).data[baru].next = -1;			//jika list sebelum ditengah
		
		else (*L).data[baru].next = (*L).data[prev].next;					//jika list ditengah
		
		(*L).data[prev].next = baru;
	}
	else printf("sudah tidak dapat ditambahkan\n");			//proses jika array penuh
	
}

void addLast(char nama[],char no_pegawai[],int gaji_pokok,list *L){
	
	if((*L).first == -1) addFirst(nama,no_pegawai,gaji_pokok,L);		//proses jika list masih kosong
	else{													//proses jika list telah berisi elmt	
		if(countElement(*L) < n){						//proses jika array belum penuh
			
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1) prev = (*L).data[prev].next;	//iterasi
			addAfter(prev, nama,no_pegawai,gaji_pokok,L);
		}
		else printf("sudah tidak dapat ditambahkan\n");	//proses jika array penuh
	}
	
}

void delFirst(list *L){
	
	if((*L).first != -1){	
		int hapus = (*L).first;
		if(countElement(*L) == 1) (*L).first = -1;				//jika satu elmt
		else (*L).first = (*L).data[(*L).first].next;			//jika banyak elmt
	
		(*L).data[hapus].next = -2;	//elmt awal sebelumnya dikosongkan
	}
	else printf("list kosong\n");	
	
}


void delAfter(int prev,list *L){
	int hapus = (*L).data[prev].next;
	
	if(hapus != -1){
		if((*L).data[hapus].next == -1) (*L).data[prev].next = -1;			//jika sebelum ditengah
		else (*L).data[prev].next = (*L).data[hapus].next;					//jika ditengah
		
		(*L).data[hapus].next = -2;		//penghapusan elmt
	}
}

void delLast(list *L){
	
	if((*L).first != -1){
		
		if(countElement(*L) == 1) delFirst(L);				//jika satu elmt
		else{
			int hapus = (*L).first;
			int prev;
			
			while ((*L).data[hapus].next != -1){		//iterasi
				prev = hapus;
				hapus = (*L).data[hapus].next;
			}
			delAfter(prev, L);							//elmt sebelum elmt terakhir menjadi elmt terakhir
		}
	}
	else printf("list kosong\n");					//proses jika list kosong
	
}

void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--){
		delLast(L);
	}
	
}

void printElemen(list L){
	
	if(L.first != -1){
		//inisialisasi	
		int elmt = L.first;
		data pegawai[100];
		
		int i = 0;
		
		while(elmt != -1){
			
			if(L.data[elmt].elmt.bonus_gaji!=0)
			printf("%s %s %d\n",L.data[elmt].elmt.nama,L.data[elmt].elmt.no_pegawai,L.data[elmt].elmt.total_gaji);		//output
		
			elmt = L.data[elmt].next;
			i++;									//iterasi
		}

	}
	else printf("List Kosong\n");
}

void bubble_sort(list *L){
	
	int tukar,i;
	elemen temp;
	
	do{
		tukar = 0;
		for(i=0;i<countElement(*L)-1;i++){
			if((*L).data[i].elmt.total_gaji>(*L).data[i+1].elmt.total_gaji){
				temp.elmt = (*L).data[i].elmt;
				(*L).data[i].elmt = (*L).data[i+1].elmt;
				(*L).data[i+1].elmt = temp.elmt;
				tukar = 1;
			}
		}
	}while(tukar==1);
}

void delPegawai(list *L){
	
	if((*L).first != -1){
		if((*L).data[(*L).first].elmt.bonus_gaji==0){
			int hapus = (*L).first;
			if(countElement(*L) == 1) (*L).first = -1;				//jika satu elmt
			else (*L).first = (*L).data[(*L).first].next;			//jika banyak elmt
		
			(*L).data[hapus].next = -2;	//elmt awal sebelumnya dikosongkan
		}
	}
	else printf("list kosong\n");
}


void kumulatif(char no_undian[],list *L){
	
	if((*L).first != -1){
		
		int elmt = (*L).first;
		int tampung = 0,i;
		
		while(elmt != -1){
			(*L).data[elmt].elmt.bonus_gaji = bonus((*L).data[elmt].elmt.no_pegawai,no_undian,(*L).data[elmt].elmt.gaji_pokok);
			(*L).data[elmt].elmt.total_gaji = (*L).data[elmt].elmt.gaji_pokok + (*L).data[elmt].elmt.bonus_gaji;
			
			elmt = (*L).data[elmt].next;
		}
		
	}
	
}

