/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,Bu sınıf  fonksiyon sayısını hesaplar. Class ve fonksiyon ayırmak için önemli bir adımdır. 
* </p>
*/
package Odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FunctionCounter { 
	public static int functionCounter(String content) //public, private, protected tan yararlanarak fonksiyon sayısı bulunmuştur.
	{
		String function= "(public|private|protected)?\\s*\\w+\\s+\\w+\\s*\\(.*?\\)\\s*\\{";
		int counter=0;

		Pattern pattern = Pattern.compile(function);
		Matcher matcher = pattern.matcher(content);

		while (matcher.find()) 
		{
			counter++;
		}

		return counter;
	}
}
