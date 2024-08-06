/**
*
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
* @since 01.04.2024
* <p>
* Bu sınıf, githubtan çekilen dosyadaki java uzantılı ve classa sahip olan dosyaları ayıklar.
* </p>
*/

package Odev;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class FindJavaFiles {
	public static List<String> findJavaFilesWithClasses(File directory) {
		List<String> javaFiles = new ArrayList<>();
		findJavaFilesWithClasses(directory, javaFiles);
		return javaFiles;
	}
	
	public static boolean className(File file) {
		boolean className = false;
		try {
			className = ReadJavaFiles.readFileContent(file.getAbsolutePath()).contains(" class "); //class ları ayıkla.
		} catch (Exception e) {
			e.printStackTrace();
		}
		return className;
	}
	
	public static void findJavaFilesWithClasses(File directory, List<String> javaFiles) {
		File[] files = directory.listFiles();
		if (files != null) {
			for (File file : files) {
				if (file.isDirectory()) {
					findJavaFilesWithClasses(file, javaFiles);
				} else if (file.getName().endsWith(".java")) { //java uzantılı dosyaları al.
					if (className(file)) {
						javaFiles.add(file.getAbsolutePath());
					}
				}
			}
		}
	}
}
