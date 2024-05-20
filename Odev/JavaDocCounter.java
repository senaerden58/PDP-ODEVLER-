/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,ekran çıktısıyla uyumlu bir şekilde hesaplanmış bir javadoc sayıcı fonksiyon yazılmıştır. "/** *\ " ları regex yardımı ile sayar.
* </p>
*/
package Odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JavaDocCounter { 
	public static int javadocCounter(String content) { //ekran çıktısına uygun sayılmaya çalışılmıştır.
		String javaDocRegex = "/\\*\\*(?s:(?!\\*/).)*\\*/";

		int counter = 0;
		int java=0;

		Pattern pattern = Pattern.compile(javaDocRegex);
		Matcher matcher = pattern.matcher(content);

		while (matcher.find()) {
			java++;
			String javaDocBlock = matcher.group();
			String[] lines = javaDocBlock.split("\n");
			for (String line : lines) {
				if (line.trim().startsWith("*")) {
					counter++;
				}
			}
		}
		
		return counter-java;
	}
}


