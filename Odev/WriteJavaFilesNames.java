/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf,istenilen çıktıyı sağlamak için yazılmış olan fonksiyonları çağırır ve çıktının aynısını sağlar.
* </p>
*/
package Odev;

import java.io.File;
import java.util.List;

public class WriteJavaFilesNames {
	public static List<String> writeJavaFilesNames(File directory) {
		List<String> javaFiles = FindJavaFiles.findJavaFilesWithClasses(directory);

		for (String javaFile : javaFiles) {
			File file = new File(javaFile);
			System.out.println("Sınıf: " + file.getName());  //java uzantılı dosyaların isimlerini getirir.

			String content = ReadJavaFiles.readFileContent(javaFile); 
			
			int javadoc=JavaDocCounter.javadocCounter(content);  
			System.out.println("Javadoc Satır Sayısı: "+javadoc); //javadocları bulan fonksiyonu çağırır. 
			
			int comment=CommentCounter.commentCounter(content); 
			System.out.println("Yorum Satırı Sayısı: "+comment); //yorum satırlarını bulan fonksiyonları çağırır. 
			
			int line=LineCounterWithoutComment.linesWithoutComment(content); 
			System.out.println("Kod satır sayısı: "+line);  //yorumsuz ve boşluksuz satırları çağırır.

			int codeLine=LineCounter.lineCounter(content);
			System.out.println("LOC: "+codeLine);  //bütün kod satırlarını bulan fonksiyonu çağırır.
			
			int function=FunctionCounter.functionCounter(content);
			System.out.println("Fonsiyon sayısı: "+function);  //fonksiyon sayısı bulan fonksiyonu çağırır.
			
			CommentDeviationPercentage.percentage(content);

			System.out.println("-----------------------------------------"); //çıktıya uygun desen verir.
		}
		return javaFiles; 
	}
}
