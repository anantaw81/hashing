//Created by Ananta (Impementasi Hash Table)
#include <stdio.h>
#include <stdlib.h>
#define BATAS 10  //maksimal jumlah himpunan yaitu 10 

/** Prototype fungsi untuk menu setiap pilihan.
 */
void menu_linear_probing();
void menu_quadratic_probing();
void menu_chaining();

/** Prototype fungsi hash untuk semua teknik.
 */
int hashfunc(int key);

/** Prototype fungsi & tabel untuk Chaining .
 */
struct chash{
	int key;
	struct chash *next;
	};

struct chash *table_chain[BATAS];

void insert_chain(int key);
void display_chain();
struct chash *search_chain(int key);
void hapus_chain(int key);

/** Prototype fungsi & tabel untuk Quadratic Probing .
 */
struct hash{
	int key;
	};
struct hash *table[BATAS];
struct hash *dummyhapus;

struct hash *search(int key);
void insert(int key);
struct hash *delete(int key_y);
void display(struct hash **dont);


/** Prototype fungsi & tabel untuk Linear Probing .
 */
struct hash *table_probe[BATAS];

struct hash *search_probe(int key);
void insert_probe(int key);
struct hash *delete_probe(int key_y);

/** Main --------------------------------------->
 */

int main()
{
	int y;
	do{
	puts("*************************************");
	puts(" Data yang dimasukkan berupa ANGKA ! ");
	puts(" Ruang HIMPUNAN berjumlah 10 !       ");
	puts("*************************************");
	puts(" ");
	puts("Pilihan Penyimpanan Hash Table");
	puts("1. Linear Probing");
	puts("2. Quadratic Probing");
	puts("3. Chaining");
	puts("4. Keluar");
	printf("Masukkan pilihan : ");
	scanf("%d", &y);
	if(y == 1){
		menu_linear_probing();
		}
		else if(y==2){
			menu_quadratic_probing();
			}else if(y==3){
				menu_chaining();
				}else if(y==4){
					break;
					}
					else{
						puts("Pilihan yang Anda masukkan salah !");
					}
	}while(1);
	return 0;
}

void menu_linear_probing(){
	int y, data_y;
	do{
	puts("1. Tambah Data(Key)");
	puts("2. Lihat Data");
	puts("3. Hapus data");
	puts("4. Cek data");
	puts("5. Keluar");
	printf("Masukkan pilihan : ");
	scanf("%d", &y);
	if(y == 1){
		printf("Masukkan Data :");
		scanf("%d", &data_y);
		insert_probe(data_y);
		}
		else if(y==2){
			display(table_probe);
			}else if(y==3){
				printf("Masukkan Data yang ingin dihapus :");
				scanf("%d", &data_y);
				delete_probe(data_y);
				}
				else if(y==4){
					printf("Masukkan Data yang ingin dicari :");
					scanf("%d", &data_y);
					if(search_probe(data_y) == NULL){
						printf("Tidak ditemukan !\n\n");
					}
					else{
						printf("Ditemukan !\n\n");}
					}else if(y==5){
						break;
						}
						else{
							puts("Pilihan yang Anda masukkan salah !");
						}
	}while(1);
	}

void menu_quadratic_probing(){
	int y, data_y;
	do{
	puts("1. Tambah Data(Key)");
	puts("2. Lihat Data");
	puts("3. Hapus data");
	puts("4. Cek data");
	puts("5. Keluar");
	printf("Masukkan pilihan : ");
	scanf("%d", &y);
	if(y == 1){
		printf("Masukkan Data :");
		scanf("%d", &data_y);
		insert(data_y);
		}
		else if(y==2){
			display(table);
			}else if(y==3){
				printf("Masukkan Data yang ingin dihapus :");
				scanf("%d", &data_y);
				delete(data_y);
				}else if(y==4){
					printf("Masukkan Data yang ingin dicari :");
					scanf("%d", &data_y);
					if(search(data_y) == NULL){
						printf("Tidak ditemukan\n");
					}
					else{
						printf("Ditemukan !\n");}
					}else if(y==5){
						break;
						}
						else{
							puts("Pilihan yang Anda masukkan salah !");
						}
	}while(1);
	}

void menu_chaining(){
	int y, data_y;
	do{
	puts("1. Tambah Data(Key)");
	puts("2. Lihat Data");
	puts("3. Hapus data");
	puts("4. Cek data");
	puts("5. Keluar");
	printf("Masukkan pilihan : ");
	scanf("%d", &y);
	if(y == 1){
		printf("Masukkan Data :");
		scanf("%d", &data_y);
		insert_chain(data_y);
		}
		else if(y==2){
			display_chain();
			}else if(y==3){
				printf("Masukkan Data yang ingin dihapus :");
				scanf("%d", &data_y);
				hapus_chain(data_y);
				}else if(y==4){
					printf("Masukkan Data yang ingin dicari :");
					scanf("%d", &data_y);
					if(search_chain(data_y) == NULL){
						printf("Tidak ditemukan\n");
					}
					else{
						printf("Ditemukan !\n");}
					}
					else if(y==5){
						break;
						}
						else{
							puts("Pilihan yang Anda masukkan salah !");
					}
	}while(1);
	}




int hashfunc(int key){
	return key % BATAS;
	}



//Fungsi untuk teknik Chaining ----------------------------------------------------------------

void insert_chain(int key){
	struct chash *baru = (struct chash *)malloc(sizeof(struct chash));
	struct chash *bantu;
	baru->key = key;
	baru->next = NULL;
	int hash_index = hashfunc(key);
	bantu = table_chain[hash_index];
	if(bantu == NULL){
		table_chain[hash_index] = baru;
		}
	else{
		while(bantu->next != NULL){
			bantu = bantu->next;
			}
		bantu->next = baru;
		}
	}

void display_chain(){
	struct chash *bantu;
	puts("");
	for(int i =0; i<BATAS; i++){
		printf("[%d] ", i);
		bantu = table_chain[i];
		if(bantu == NULL){
			printf(" ~~ ");
		}
		else{
			do{
			printf(" %d ", bantu->key);
			bantu = bantu->next;
			}while(bantu != NULL);
			}
			puts("");
		}
	}

struct chash *search_chain(int key){
	int hash_index = hashfunc(key);
	struct chash *bantu;
	if(table_chain[hash_index] != NULL){
	
	bantu = table_chain[hash_index];
	if(bantu->key==key){
		return bantu;
		}
	else{
		
		while(bantu->next != NULL){
			if(bantu->key != key){
			bantu = bantu->next;
			}		
			return bantu;
		}
		}
		
	}
		return NULL;
	}

void hapus_chain(int key){
	int hash_index = hashfunc(key);
	struct chash *bantu, *temp, *diam;

	temp = NULL;
	diam = table_chain[hash_index];
	bantu = NULL;
	while(table_chain[hash_index]){
		if(table_chain[hash_index]->key != key){
			bantu = table_chain[hash_index];
			table_chain[hash_index] = table_chain[hash_index]->next;
			}
		else{
			if(bantu != NULL){
				bantu->next = table_chain[hash_index]->next;
				temp = table_chain[hash_index];
				table_chain[hash_index] = NULL;
				table_chain[hash_index] = diam; 
				free(temp);
				}
			else{
				table_chain[hash_index] = table_chain[hash_index]->next;
				free(diam);
				}
			
			break;
			}
			
	}
	}


//-------------------------------------------------------------------------end
//Fungsi untuk teknik Quadratic ----------------------------------------------

struct hash *search(int key){
	int i =1, hello_world;
	int hash_index = hashfunc(key);
	hello_world = hash_index;
	//linear_probe
	while(table[hash_index] != NULL){
		if(table[hash_index]->key == key){
			return table[hash_index];
			}
		hash_index = hello_world + i + i*i;
		i++;
		
		hash_index = hash_index % BATAS;
		}
		return NULL;
	}
	
void insert(int key){
	int i =1, hello_world;
	struct hash *baru = (struct hash *)malloc(sizeof(struct hash));
	baru->key = key;
	
	int hash_index = hashfunc(key);
	hello_world = hash_index;
	//linear_probe
	while(table[hash_index] != NULL && table[hash_index]->key != -1 ){
		hash_index = hello_world + i + i*i;
		i++;
		hash_index = hash_index % BATAS;
		}
	table[hash_index] = baru; 
	}

struct hash *delete(int key_y){
	int i = 1, hello_world;
	dummyhapus = (struct hash*) malloc(sizeof(struct hash));
	dummyhapus->key = -1;
	int hash_index = hashfunc(key_y);
	hello_world = hash_index;
	
	while(table[hash_index] != NULL){
		if(table[hash_index]->key == key_y){
			struct hash *temp = table[hash_index];
			table[hash_index] = dummyhapus;
			return temp;
			}
		hash_index = hello_world + i + i*i;
		i++;
		hash_index= hash_index % BATAS;
		}
	return NULL;
	}

void display(struct hash **dont){
	for(int i=0; i<BATAS; i++){
		printf("[%d]", i);
		if(dont[i] == NULL || dont[i]->key == -1){
			printf(" ~ \n");
			}
		else{
			printf("%d \n", (*dont[i]).key);
			}
		}
	}
	
//-------------------------------------------------------------------------end
//Fungsi untuk teknik Linear    ----------------------------------------------

struct hash *search_probe(int key){
	int i=1, hello_world;
	int hash_index = hashfunc(key);
	hello_world = hash_index;
	
	while(table_probe[hash_index] != NULL){
		if(table_probe[hash_index]->key == key){
			return table_probe[hash_index];
			}
		hash_index = hello_world + i++;
		hash_index = hash_index%BATAS;
		}
	return NULL;
	}
	
void insert_probe(int key){
	struct hash *baru = (struct hash*)malloc(sizeof(struct hash));
	baru->key = key;

	int hash_index = hashfunc(key);
	int hello_world = hash_index;
	int i=1;
	
	while(table_probe[hash_index] != NULL && table_probe[hash_index]->key != -1){
		hash_index = hello_world + i++;
		hash_index = hash_index%BATAS;
		}
	table_probe[hash_index] = baru; 
	}
	
struct hash *delete_probe(int key_y){
	int i =1;
	int hello_world;
	dummyhapus = (struct hash *) malloc (sizeof(struct hash));
	dummyhapus->key = -1;
	int hash_index = hashfunc(key_y);
	hello_world = hash_index;
	
	while(table_probe[hash_index] != NULL){
	    if(table_probe[hash_index]->key == key_y){
			struct hash *temp;
			temp = table_probe[hash_index];
			table_probe[hash_index] = dummyhapus;
			return temp;
			}
		hash_index = hello_world + i++;
		hash_index = hash_index % BATAS;
		} 
	return NULL;
	}
