/*
Final Projek Struktur Data
Anggota Kelompok:
1. I Gede Widnyana (2208561016)
2. I Gede Widiantara Mega Saputra (2208561022)
Kelas C
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <limits.h>
#define INFINITY 9999
#define SIZE 100
#define V 10
#include<conio.h>

struct Barang{
	int kodebarang;
	char namabarang[20];
	int stock;
	struct Barang *next;
}; typedef struct Barang Brg;

struct Pemesanan{
	struct Pemesanan *next;
	int kodepesanan;
	char nama[20];
	int kodebarangpesanan;
	char namabarang[20];
	int jumlahpesanan;
	int kota_tujuan;
	int kota_asal;
	int tanggal;
	int bulan;
	int tahun;
	struct Barang Brg;
}; typedef struct Pemesanan Pesan;

struct Login{
	struct Login *next;
	char username[50];
	char password[50];
}akun[50]; typedef struct Login Lg;

struct Login* userhead = NULL;

void lihatbarang();
void tambahbarang();
void updatebarang();
void hapusbarang();
void detailbarang();
void tambahpemesanan();
void lihatpemesanan();
void dijkstra(int G[V][V],int n, int startnode, int targetnode);
void ubahgraph();
void buatakun();

Lg* loginakun(Lg *);
void lihatakun(Lg *);
struct Barang *head = NULL;
struct Barang *p = NULL;
struct Pemesanan *head1 = NULL;

int graph[V][V] =  {{0, 15, 33, 0, 0, 0, 0, 0, 0},
				   { 15, 0, 0, 11, 0, 0, 0, 0, 0},
				   { 33, 0, 0, 0, 33, 0, 0, 0, 0},
				   { 0, 11, 0, 0, 0, 0, 0, 0, 74},
				   { 0, 0, 33, 0, 0, 39, 0, 0, 0},
				   { 0, 0, 0, 0, 39, 0, 43, 0, 0},
				   { 0, 0, 0, 0, 0, 43, 0, 96, 0},
				   { 0, 0, 0, 0, 0, 0, 96, 0, 67},
				   { 0, 0, 0, 74, 0, 0, 0, 67, 0}};

int main(){
	int pilih, fitur;
	Lg *lg;
	lg = NULL;

	system("cls"); system("color 06");
	printf("\n\t====================================================\n");
	printf("\t=          FINAL PROJECT STRUKTUR DATA             =\n");
	printf("\t=APLIKASI MANAJEMEN PEMESANAN DAN PENGIRIMAN BARANG=\n");
	printf("\t====================================================\n");
	printf("\t=      I GEDE WIDNYANA                [2208561016] =\n");
	printf("\t=      I GEDE WIDIANTARA MEGA SAPUTRA [2208561022] =\n");
	printf("\t====================================================\n");
	printf("\tTekan sembarang untuk memulai program!");
	getch();

	do{
    	menu2:
		system("cls");
		system("color 06");
		printf("\t=================================================================== \n");
		printf("\t=        APLIKASI MANAJEMEN PEMESANAN DAN PENGIRIMAN BARANG	  =\n");
		printf("\t=================================================================== \n");
		printf("\n\tSilakan login terlebih dahulu! \n");
		printf("\n\tMenu:");
		printf("\n\t1. Login");
		printf("\n\t2. Daftar Akun");
		printf("\n\t0. Keluar");
		printf("\n\tPilih menu: ");
		scanf("%d", &fitur);

		switch (fitur) {
    	case 1:
        	lg = loginakun(lg);
        	if(lg == NULL){
				break;
				goto menu2;
        	}
			else{
				break;
				goto menu;
        	}

    case 2:
        buatakun();
        printf("\n\tAnda telah berhasil mendaftar akun!");
        printf("\n\tSilakan login dengan akun yang baru dibuat.");
        getch();
        system("cls");
        lg = loginakun(lg); 
        if(lg == NULL){
            goto menu2;
        }
        else{
            break;
        }
    case 0:
        exit(1);
    default:
        printf("\n\tMaaf, pilihan tidak valid. Silakan coba lagi.");
        getch();
        goto menu2;

	}
	}while(fitur!=0 && lg==NULL);

	do{
		menu:
		system("cls"); system("color 06");
		printf("\n\t====================================================\n");
		printf("\t=                    Menu Fitur                    =\n");
		printf("\t====================================================\n");
		printf("\t1. Informasi Barang\n");
		printf("\t2. Informasi Pemesanan\n");
		printf("\t3. Informasi Akun & Graph\n");
		printf("\t4. Keluar\n");
		printf("\t====================================================\n");
		printf("\tMasukkan Pilihan Anda : ");
		scanf("%d", &fitur);

		if(fitur==1){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1. Tambah Barang\n");
			printf("\t2. Ubah Barang\n");
			printf("\t3. Lihat Barang\n");
			printf("\t4. Hapus Barang\n");
			printf("\t5. Lihat Detail Barang\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					tambahbarang();
					break; goto menu;
				case 2 :
					updatebarang();
					break; goto menu;
				case 3 :
					lihatbarang();
					break; goto menu;
				case 4 :
					hapusbarang();
					break; goto menu;
				case 5:
					detailbarang();
					break; goto menu;
			}
		}
		else if(fitur==2){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1.  Pemesanan Barang\n");
			printf("\t2.  Lihat Proses Pengiriman\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					tambahpemesanan();
					break; goto menu;
				case 2 :
					lihatpemesanan(graph);
					break; goto menu;
			}
		}
		else if(fitur==3){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1.  Lihat Akun Saya\n ");
			printf("\t2.  Ubah Data Graph\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					lihatakun(lg);
					break; goto menu;
				case 2 :
					ubahgraph();
					break; goto menu;
			}
		}
		else if(fitur==4){
			system("cls");
			printf("\n\tTerima kasih Telah Menggunakan Program ini.");
			getch(); exit(0); break;
		}
		else{
			printf("\n\tMaaf Pilihan Fitur Tidak Tersedia, Silahkan Menginput Ulang!");
			getch(); break;	goto menu;
		}
	}

while(pilih != 10);
return 0;
akhir:
	exit(0);
}

struct Login* loginakun(struct Login* lg) {
    struct Login* log = (struct Login*)malloc(sizeof(struct Login));
    log->next = NULL;

    system("cls");
    system("color 06");

    printf("\n\t====================================================\n");
    printf("\t=                    LOGIN AKUN                    =\n");
    printf("\t====================================================\n");

    fflush(stdin);

    printf("\tUSERNAME    : ");
    scanf("%s", log->username);

    printf("\tPASSWORD    : ");
    scanf("%s", log->password);

    bool validCredentials = false;

    FILE* file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("\n\tDatabase file error!\n");
        getch();
        free(log);
        return NULL;
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
    char username[50], password[50];
    sscanf(buffer, "%s %s", username, password);

    if (strcmp(log->username, username) == 0 && strcmp(log->password, password) == 0) {
        validCredentials = true;
        break;
    }
}
    fclose(file);

    if (!validCredentials) {
        printf("\n\tUsername atau password Anda salah. Silakan login kembali.\n");
        getch();
        free(log);
        return NULL;
    }

    if (lg == NULL) {
        lg = log;
    } else {
        log->next = lg;
        lg = log;
    }

    printf("\n");
    return lg;
}

void buatakun() {
    struct Login* newUser = (struct Login*)malloc(sizeof(struct Login));

    printf("\nMasukkan Username: ");
    scanf("%s", newUser->username);

    printf("\nMasukkan Password: ");
    scanf("%s", newUser->password);

    newUser->next = NULL;

    FILE* file = fopen("data.txt", "a");

    if (file == NULL) {
        printf("\n\tDatabase file error!\n");
        getch();
        free(newUser);
        return;
    }

    fprintf(file, "%s %s\n", newUser->username, newUser->password);

    fclose(file);
}

void lihatakun(Lg *lg){

	system("cls");
	printf("\n\t===================================================\n");
	printf("\t=                  Lihat Akun Saya                  =\n");
	printf("\t=====================================================");

	while(lg != NULL){
		printf("\n\tUsername	: %s",lg->username);
		printf("\n\tPassword	: ***********");
		lg= lg->next;
	} 
	getch(); 
	system("cls");
}

void masukpemesanan(int kodpes,int kodbarpes, int jumpes,int tgl,int bln,int thn,char nampes[],char nambar[],int tujuan,int asal){
	struct Pemesanan* newnode = (struct Pemesanan*)malloc(sizeof(struct Pemesanan));
	newnode->kodepesanan = kodpes;
	strcpy(newnode->nama, nampes);
	newnode->kodebarangpesanan = kodbarpes;
	strcpy(newnode->namabarang, nambar);
	newnode->jumlahpesanan = jumpes;
	newnode->tanggal = tgl;
	newnode->bulan = bln;
	newnode->tahun = thn;
	newnode->kota_asal= asal;
	newnode->kota_tujuan = tujuan;
	newnode->next = head1;
	head1 = newnode;
}

void tambahpemesanan(){
	system("cls"); system("color 06");
    int kodpes,kodbarpes, jumpes, tgl,bln, thn,tujuan,asal;
    char nampes[50],nambar[40];
	fflush(stdin);
	printf("\t=============================================\n");
	printf("\t            Buat Pemesanan Barang            \n");
	printf("\t=============================================\n");
	printf("\tKode Pesanan	: ");
	scanf ("%d",&kodpes); fflush(stdin);
	printf("\tNama Pemesan	: ");
	scanf("%s", &nampes); 	fflush(stdin);
	printf("\tKode Barang	: ");
	scanf ("%d",&kodbarpes); fflush(stdin);
	printf("\tNama Barang	: ");
	scanf("%s", &nambar); 	fflush(stdin);
	printf("\tJumlah Pesanan	: ");
	scanf("%d", &jumpes); 	fflush(stdin);
	printf("\tTanggal     	: ");
	scanf("%d", &tgl); 	fflush(stdin);
	printf("\tBulan      	: ");
	scanf("%d", &bln); 	fflush(stdin);
	printf("\tTahun      	: ");
	scanf("%d", &thn); 	fflush(stdin);
	printf("\tDaftar Daerah Asal   : ");
	printf("\n\t0. Denpasar");
	printf("\n\t1. Badung");
	printf("\n\t2. Gianyar");
	printf("\n\t3. Tabanan");
	printf("\n\t4. Klungkung");
	printf("\n\t5. Karangasem");
	printf("\n\t6. Bangli");
	printf("\n\t7. Buleleng ");
	printf("\n\t8. Jembrana");
	printf("\n\tPilih Daerah Asal : ");
	scanf("%d", &asal);
	printf("\tDaerah Tujuan :");
	printf("\n\t0. Denpasar");
	printf("\n\t1. Badung");
	printf("\n\t2. Gianyar");
	printf("\n\t3. Tabanan");
	printf("\n\t4. Klungkung");
	printf("\n\t5. Karangasem");
	printf("\n\t6. Bangli");
	printf("\n\t7. Buleleng ");
	printf("\n\t8. Jembrana");
	printf("\n\tPilih Daerah Tujuan : ");
	scanf("%d", &tujuan);

	masukpemesanan(kodpes,kodbarpes, jumpes, tgl,bln, thn,nampes,nambar,tujuan,asal);
	getch();system("cls");
}

void lihatpemesanan(int graph[V][V]){
	struct Pemesanan* lihat;
	system("cls"); system("color 06");

	if (head1 == NULL){
		printf (" Tidak Ada Proses Pemesanan Barang ");
	}
	else{
		printf("\n\t=============================================\n");
		printf("\t         Lihat Proses Pemesanan Barang       \n");
		printf("\t=============================================");
		lihat = head1;
		while (lihat!= NULL){
			printf("\n\n\tKode Pesanan	: %d", lihat->kodepesanan);
			printf("\n\tNama Pemesan	: %s", lihat->nama);
			printf("\n\tKode Barang 	: %d", lihat->kodebarangpesanan);
			printf("\n\tNama Barang	: %s", lihat->namabarang);
			printf("\n\tJumlah Barang	: %d", lihat->jumlahpesanan);
			printf("\n\tTanggal Pesan   : %d", lihat->tanggal);
			printf("\n\tBulan         	: %d", lihat->bulan);
			printf("\n\tTahun         	: %d", lihat->tahun); printf("\n");
			dijkstra(graph,10,lihat->kota_asal,lihat->kota_tujuan);
			lihat = lihat->next;
		}
	}

getch(); system("cls");
}

void dijkstra(int G[V][V],int n, int startnode, int targetnode)
{
	struct Pemesanan* lihat;
	int cost[V][V],distance[V],pred[V];
	int visited[V],count,mindistance,nextnode,i,j;
	char kota[25][12] = {"Denpasar","Badung","Gianyar","Tabanan","Klungkung","Karangasem","Bangli","Buleleng", "Jembrana"};

	//Mengecek vertex yang terhubung dan mengisi bobotnya
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//Menyimpan jarak terpendek dari titik asal ke titk lainnya
	for(i=0;i<n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode; 
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1){
		mindistance=INFINITY;

		//memperbarui bobot djikstra yang awalnya bernilai tak terhingga
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i]){
				mindistance=distance[i];
				nextnode=i;
			}

		//membandingkan bobot djikstra yang sudah diupdate sebelumnya
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i]){
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
  	int a;
 	int u;
 	char tes[20][8] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};
	for(i=0;i<n;i++)
		if(i==targetnode){
			printf("\tDaerah Asal \t: %s", kota[startnode]);
			printf("\n\tDaerah Tujuan \t: %s", kota[i]);
			printf("\n\tJarak Tujuan \t: %d KM", distance[i]);
			printf("\n\tJalur \t\t: %s", kota[i]);

			j=i;
			do{
				j=pred[j];
				printf(" <- %s",kota[j]);
			}while(j!=startnode);
			
			a=distance[i];
			if (a<=30){
				u = 1;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 1 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
			else if (a<=120){
				u = 3;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 3 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
			else if (a<=180){
				u = 5;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 5 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
			else if (a>=390){
				u = 7;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 7 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
	}
}

void masukbarang(int kodbar,char nambar[],int stock1){
	struct Barang* newnode = (struct Barang*)malloc(sizeof(struct Barang));
	newnode->kodebarang = kodbar;
	strcpy(newnode->namabarang, nambar);
	newnode->stock = stock1;
	newnode->next = head;
	head = newnode;
}

void tambahbarang(){
	system("cls");
    int kodbar, stock1;
    char nambar[50];

	fflush(stdin);
	printf("\t=============================================\n");
	printf("\t            	Tambah Barang 		           \n");
	printf("\t=============================================\n");
	printf("\tKode Barang		: ");
	scanf("%d", &kodbar);  fflush(stdin);
	printf("\tNama Barang		: ");
	scanf("%s", &nambar); 	fflush(stdin);
	printf("\tStock Barang     	: ");
    scanf("%d",&stock1); 	fflush(stdin);
	masukbarang(kodbar,nambar,stock1);
	getch();system("cls");
}

void updatebarang(){
	struct Barang *current;
   	char namabarang1[50];
   	int stock1, num;
	system("cls");

	printf("\t=============================================\n");
	printf("\t            	Update Barang 		           \n");
	printf("\t=============================================\n");

	printf("\tMasukan kode barang yang ingin diubah : ");
	scanf("%d", &num);
	fflush(stdin);

	if(head==NULL){
		printf("\tList Saat ini Masih Kosong"); getch(); system("cls"); return;
	}

	current = head;
	while(current!=NULL){
	 	if(num==current->kodebarang){
	 		printf("\t=============================================\n");
	 		printf("\tMasukkan Nama Barang	: ");
	      	scanf("%s", &namabarang1);
	      	strcpy(current->namabarang, namabarang1);
	      	printf("\tMasukkan Stock Baru	: ");
	      	scanf("%d", &stock1);
	      	current->stock = stock1;
		}
		current=current->next;
	}
	printf("\tKode Barang %d Tidak Berada di dalam List", num);
	getch(); system("cls");
}

void lihatbarang(){
struct Barang* lihat;
system("cls"); printf("\n");

    if(head==NULL){
        printf("\n\tData Barang Kosong\n");
    }
    else{
    printf("\t=============================================\n");
    printf("\t=              Lihat Barang                 =\n");
    printf("\t=============================================");
    lihat = head;

		while(lihat != NULL){
            printf("\n\tKode Barang     : %d", lihat->kodebarang);
            printf("\n\tNama Barang     : %s", lihat->namabarang);
            printf("\n\tStock Barang    : %d", lihat->stock);
            lihat = lihat->next;
        }
    }
    getch(); system("cls");
}

void hapusbarang(){
system("cls");
struct Barang *temp = NULL;
int num;

	printf("\t=============================================\n");
	printf("\t            	Hapus Barang 		           \n");
	printf("\t=============================================\n");
	printf("\tMasukkan kode barang yang ingin dihapus : ");
	scanf("%d", &num);

	if(head==NULL){
		printf("\n\tList Saat ini Masih Kosong");
		getch(); 
		system("cls"); 
		return;
	}

	if(num==head->kodebarang)	
	{	
		temp = head;
		head = head->next;
		free(temp);
		return;
	}

	p = head;
	while(p->next!=NULL) 
	{	
		if(p->next->kodebarang==num){
			temp = p->next;
			p->next = temp->next;
			free(temp);
			getch(); system("CLS");
			return;
		}
		p = p->next;
	}
	printf("\n\tKode Barang %d Tidak Berada di dalam List", num);
	getch(); system("cls");
}

void detailbarang(){
system("cls"); printf("\n");
int search_detail;
int kembali;
struct Barang* detail;
struct Barang* letak;
struct Pemesanan* lihat;

    if(head==NULL){
        printf("\n\tSaat ini status barang adalah kosong\n");
    }
	else{
	 	printf("\t=============================================\n");
    	printf("\t=            Lihat Detail Barang            =\n");
    	printf("\t=============================================\n");
    	detail = head;

		while(detail != NULL){
        	printf("\n\t[%d]\t[%s] \n", detail->kodebarang, detail->namabarang);
			detail = detail->next;
		}
		printf("\tSilakan Masukan kode barang yang ingin dilihat : ");
		scanf("%d", &search_detail);

		letak = head;
		lihat = head1;
		while(letak!=NULL){
			if(search_detail==letak->kodebarang){
				printf("\n\tKode Barang		: %d", letak->kodebarang);
        		printf("\n\tNama Barang		: %s", letak->namabarang);
        		printf("\n\tStock Barang		: %d", letak->stock);
				while (lihat != NULL){
					if(letak->kodebarang == lihat->kodebarangpesanan){
						printf("\n\tNama Pemesan 		: %s \n", lihat->nama);
						lihat = lihat->next;
						kembali =1;
					}
					else{
						lihat = lihat->next;
						kembali =0;
					}
				}
				if (kembali == 0){
					printf("\n\tBarang belum dipesan");
				}
			}
			letak = letak->next;
		}
    }
    getch();
    system("cls");
}

void ubahgraph(){
	int kota_awal, kota_tujuan, jarak_baru;
	char kota[25][12] = {"Denpasar", "Badung", "Gianyar", "Tabanan", "Klungkung", "Karangasem", "Bangli", "Buleleng", "Jembrana"};
	system("cls");

	printf("\t=============================================\n");
    printf("\t=             Update Data Daerah	          =\n");
    printf("\t=============================================\n");
	printf("\tPilih Daerah yang ingin diubah\n");
	printf("\n\t0. Denpasar");
	printf("\n\t1. Badung");
	printf("\n\t2. Gianyar");
	printf("\n\t3. Tabanan");
	printf("\n\t4. Klungkung");
	printf("\n\t5. Karangasem");
	printf("\n\t6. Bangli");
	printf("\n\t7. Buleleng ");
	printf("\n\t8. Jembrana");
	printf("\n\tMasukan Daerah : ");
	scanf("%d", &kota_awal);
	fflush(stdin);

	printf("\n\tDaerah %s Ke Daerah? : ", kota[kota_awal]);
	printf("\n\t0. Denpasar");
	printf("\n\t1. Badung");
	printf("\n\t2. Gianyar");
	printf("\n\t3. Tabanan");
	printf("\n\t4. Klungkung");
	printf("\n\t5. Karangasem");
	printf("\n\t6. Bangli");
	printf("\n\t7. Buleleng ");
	printf("\n\t8. Jembrana");
	printf("\n\tMasukkan Daerah : ");
	scanf("%d", &kota_tujuan);
	fflush(stdin);
	printf("\n\tMasukkan jarak yang Baru : ");
	scanf("%d", &jarak_baru);
	fflush(stdin);

	graph[kota_awal][kota_tujuan] = jarak_baru;
	printf("\tJarak %s ke %s yang baru adalah %d Km", kota[kota_awal], kota[kota_tujuan], jarak_baru);

	getch();
   	system("cls");
}