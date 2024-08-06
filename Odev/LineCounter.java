/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,bütün koddaki satır sayısını hesaplar.(yorum satırları, boşluklar dahildir.)
* </p>
*/
package Odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LineCounter { 
	public static int lineCounter(String content) { //Bütün kod satırları "/n" den yararlanılarak bulunmuştur.
		int lineCounter=0;
		String newLine="\n";      
		Pattern pattern = Pattern.compile(newLine);
		Matcher matcher = pattern.matcher(content);
		while (matcher.find()) 
		{
			lineCounter++;

		}
		return lineCounter;
	}
}


