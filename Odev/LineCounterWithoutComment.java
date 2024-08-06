/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,koddaki yorum satıları ve boşluklar dışındaki kod satırlarını regex yardımıyla sayar.
* </p>
*/
package Odev;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LineCounterWithoutComment { 
	public static int linesWithoutEmptyLines(String content) { 
		Matcher matcher = Pattern.compile("^\\s*$", Pattern.MULTILINE).matcher(content);
		int counter = 0;
		while (matcher.find()) {
			counter++;
		}
		int withoutEmptyLines=LineCounter.lineCounter(content)-counter;
		//Bütün kod satırlarından  boş olanlar çıkmıştır.
		return withoutEmptyLines;
	}

	public static int linesWithoutComment(String content) 
	{
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
		counter=counter+java;

		int withoutComment=linesWithoutEmptyLines(content)-counter-javaComment(content)-comment(content);
		//Boşların çıkartılmış olduğu kod satırlarından şimdide yorum satırları ve javadoc lar cıkartılmıştır.
		return withoutComment;
	}

	public static int javaComment(String content)   // "/* *\" aranır. /* * *\ olarak başlayan satırların sayısı gereklidir.
	{
		String commentRegex = "//|/\\*(?![\\*])(.|\\R)*?\\*/";
		int counter = 0;
		Pattern pattern = Pattern.compile(commentRegex);
		Matcher matcher = pattern.matcher(content);

		while (matcher.find()) {
			String javaDoc = matcher.group();
			String[] lines = javaDoc.split("\n");

			for (String line : lines) {
				if (line.trim().startsWith("*")||line.trim().startsWith("/*")||line.trim().startsWith("*/")) { //böyle başlıyorsa satır olarak sayılır.
					counter++;
				}
			}
		}

		return counter;
	}

	public static int comment(String content)   // "//" olanları bulur. Ama başında kod varsa bu kod satırı olarak sayılmalıdır.
	{

		String commentRegex = "^\\s*//.*$";

		int counter = 0;
		Pattern pattern = Pattern.compile(commentRegex, Pattern.MULTILINE);
		Matcher matcher = pattern.matcher(content);

		while (matcher.find()) {
			counter++;
		}

		return counter;
	}
}