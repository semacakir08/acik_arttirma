#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	//teklif yapısını oluşturalım
	typedef struct {
		int teklifveren_no;
		double teklif;
	}teklif;

	//arttırma yapısını oluşturalım
	typedef struct {
		int teklifveren_sayisi;
		teklif teklif[];
	}arttirma;

	//ekstra bilgilerin depolanması için ürün yapısı
	typedef struct {
		char urun_adi[50];
		arttirma bid;
	}urun;
	
	urun arttirma_baslat ();
	void acikarttirma(arttirma* a);
	void fiyathesap(arttirma* a, int kazanan_no);
	
	int main(void){
	    urun ms;
		arttirma a;

		ms=arttirma_baslat();
		ms.bid = a;

		//arttırma örneğinin pointerının fonksiyon içine girilip çalıştırılması
		acikarttirma(&a);
	return 0;
	}

	//Ana açık arttırma fonksiyonu, döngüye alıp en yüksek fiyattan daha düşük bir teklif verilene kadar teklif alma
	void acikarttirma(arttirma *a) {
		printf("Acik arttirma basladi!\n");

		double enyuksek_teklif;
		int kazanan_no;
		int i;

		enyuksek_teklif = -1.0;
		kazanan_no = -1;
		for (i = 0; true; i++) {
			teklif yeniteklif;
			yeniteklif.teklifveren_no = i;

			double yeniteklif_fiyat;
			printf("yeni artirma yapin:");
			scanf("%lf", &yeniteklif_fiyat);

			yeniteklif.teklif = yeniteklif_fiyat;
			a->teklif[i] = yeniteklif;

			if (yeniteklif_fiyat > enyuksek_teklif) {
				enyuksek_teklif = yeniteklif_fiyat;
				kazanan_no = i;
			}
			else {
				fiyathesap(a, kazanan_no+1);
				break;
			}
			
		}
	}

	//Açık artırma sonlandığında son fiyatın diyagrama uygun şekilde hesaplanması ve ekranda bildirilmesi
	void fiyathesap(arttirma *a, int kazanan_no) {
		double odeme;
		odeme = 0.0;
		int i;

		for (i = 0; true; i++) {
			a->teklifveren_sayisi++;
			if (i != kazanan_no) {
				odeme += a->teklif[i].teklif;
			}
			else {
				wprintf(L"Acik arttirma tamamlandi. Odenecek Fiyat : %lf\nAcik arttirmayi kazanan numara : %d", odeme, kazanan_no);

			}
		}
	}

	//Ürün bilgisinin alınması, ürün örneğinin oluşturulması ve geri döndürülmesi
	urun  arttirma_baslat ( ){
	
		urun urun_bilgi;
		printf("urun adi:");
		gets(urun_bilgi.urun_adi);

		return urun_bilgi;
		}
	
