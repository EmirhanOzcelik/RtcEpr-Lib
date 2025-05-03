#include "RtcEpr.h"
// kullanacağınız adresi kaydetmeniz kolaylık sağlar
#define zaman_epr_adres 5
void setup()
{
    zaman.setup(zaman_epr_adres); // eeprom kaydı için 10. adresten başladık sistem 10 adres kullanır yani bir sonraki min kayıt adresiniz 20 olmalıdır

    epr.yaz8(29, 255);     // örnek kullanım 29.adrese 255 degerini yazdık
    epr.yaz16(30, 10000);  // örnek kullanım için 30. adresden başlayacak şekilde 2 adreslik veri yazdık eger veriniz 255den büyükse yaz16 kullanmalısınız.Şu an 30.ve 31. adreslerde veri kaydı var
    int a = epr.oku8(29);  // a = 255
    int b = epr.oku16(30); // b = 10000
}
void loop()
{
    if (millis() - gecen_zaman >= g_ms)
    {
        gecen_zaman = millis(); 
        // burda rtc mantıgında hatasıza yakın derecede tarih hesabı yapılır, kullandıgınız makine yenilenme süresini (örnekte g_ms=50 kullanıldı) girdi olarak yazmanız gerekiyor
        zaman.millis_saat(g_ms); 
    }
}