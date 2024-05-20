/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf, "//" ve "/* *\" yorum satırlarını ayıklar ve regex yardımıyla örnek ekran çıktısındaki kurallara göre sayar. .
* </p>
*/
package Odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CommentCounter { // "/* *\" ve "//" aranmıştır. Çıktıya uygun sayılmıştır.
	public static int commentCounter(String content) {
		String commentRegex = "//|/\\*(?![\\*])(.|\\R)*?\\*/";
		int counter=0;

		Pattern pattern = Pattern.compile(commentRegex);
		Matcher matcher = pattern.matcher(content);

		while (matcher.find()) 
		{
			counter++;
		}

		return counter;
	}
}



