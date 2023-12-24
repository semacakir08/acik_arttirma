# acik_arttirma
# program hakkında
Programı başlattığınızda ilk olarak ürün ismi girmeniz istenecek. 50 karakterlik bir uzunluk sınırı var.

Ardından başlangıç fiyatını -1.0 a otomatik olarak ayarlayıp ilk arttırmayı girmenizi isteyecek.

İlk artırmanın ardından girdiğiniz her değer fiyatın üzerine eklenecek. Son girilen arttırmadan daha düşük bir değer girilirse açık arttırma sonlanacaktır.

Açık arttırma sonlandıktan sonra ödemeyi hesaplama fonksiyonunda son fiyat hesaplanacak ve ekrana yazdırılacaktır.

Girilen her arttırma için Teklif yapısının bir örneği oluşturulup arttırma yapısındaki teklif elemanına eklenecektir.

Teklif elemanının oluşturulan her örneğine teklif veren kişinin numarası da atanacaktır. Bu atama daha sonra ödeme hesaplarken kullanılacaktır.

Fonksiyonlar arasında arttırma ve teklifler işaretçiler aracılığıyla taşınmaktadır.

# structure
C programlama dilinde, struct, bir bellek bloğunda tek bir ad altında fiziksel olarak gruplandırılmış değişkenler 
listesini tanımlayan ve farklı değişkenlere tek bir işaretçi aracılığıyla erişilmesine izin veren bileşik bir veri türüdür.
Bu kodda structure olarak arttirma,urun,teklif bulunmaktadır.



![93e5efff-aea3-4015-811f-eca14ae4e308](https://github.com/semacakir08/acik_arttirma/assets/153114298/2918822e-118f-49d4-ac01-f4618010994f)

# kod
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	//teklif yapÄ±sÄ±nÄ± oluÅŸturalÄ±m
	typedef struct {
		int teklifveren_no;
		double teklif;
	}teklif;

	//arttÄ±rma yapÄ±sÄ±nÄ± oluÅŸturalÄ±m
	typedef struct {
		int teklifveren_sayisi;
		teklif teklif[];
	}arttirma;

	//ekstra bilgilerin depolanmasÄ± iÃ§in Ã¼rÃ¼n yapÄ±sÄ±
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

		//arttÄ±rma Ã¶rneÄŸinin pointerÄ±nÄ±n fonksiyon iÃ§ine girilip Ã§alÄ±ÅŸtÄ±rÄ±lmasÄ±
		acikarttirma(&a);
	return 0;
	}

	//Ana aÃ§Ä±k arttÄ±rma fonksiyonu, dÃ¶ngÃ¼ye alÄ±p en yÃ¼ksek fiyattan daha dÃ¼ÅŸÃ¼k bir teklif verilene kadar teklif alma
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

	//AÃ§Ä±k artÄ±rma sonlandÄ±ÄŸÄ±nda son fiyatÄ±n diyagrama uygun ÅŸekilde hesaplanmasÄ± ve ekranda bildirilmesi
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

	//ÃœrÃ¼n bilgisinin alÄ±nmasÄ±, Ã¼rÃ¼n Ã¶rneÄŸinin oluÅŸturulmasÄ± ve geri dÃ¶ndÃ¼rÃ¼lmesi
	urun  arttirma_baslat ( ){
	
		urun urun_bilgi;
		printf("urun adi:");
		gets(urun_bilgi.urun_adi);

		return urun_bilgi;
		}
	

