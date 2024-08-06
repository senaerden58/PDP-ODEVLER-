
/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,yorum sapma yüzdesini istenilen kurallara göre hesaplar.İlk olarak double hesaplar sonra "." dan sonraki
*  3. basamağa göre yuvarlar ve stringe çevirerek sadece "." dan sonra 2 satır yazılmasını sağlar.
* </p>
*/package Odev;

public class CommentDeviationPercentage 
{
	public static void percentage(String content) //Verilmiş olan formül koda çevirirlmiştir. 
	{
		//double olarak hesaplanmıştır.
		double yg =(((double)JavaDocCounter.javadocCounter(content) + (double)CommentCounter.commentCounter(content))*0.8)/(double)FunctionCounter.functionCounter(content);
		double yh=((double)LineCounterWithoutComment.linesWithoutComment(content)/(double)FunctionCounter.functionCounter(content))*0.3;
		double percentage=((100*(double)yg)/(double)yh)-100;
		
		String converted=convertToString(percentage);
		
		System.out.println("Yorum sapma yüzdesi: %"+converted);
	}
	
	public static String convertToString(double percentage)
	{
		percentage = percentage * 100.0; //100 le çarpılarak "." nın 2 basamak kayması sağlanmıştır.
		long roundedNumber = Math.round(percentage);  //kaydırılan sayı yuvarlanmıştır. 
		double roundedAndConvertedNumber = roundedNumber / 100.0; //eski haline getirilmiş.
		return String.format("%.2f", roundedAndConvertedNumber); //string e çevirerek noktadan sonraki 2 basamağın alınması sağlanmıştır.
	}

}


