package com.example;

import ij.IJ;
import ij.ImagePlus;
import ij.plugin.PlugIn;
import ij.process.ImageProcessor;
	 
public class Trabalho1 implements PlugIn {
	public void run(final String arg) {
		final ImagePlus newImage = IJ.createImage("Random Image for test", "8-bit", 40, 40, 1);
		final ImageProcessor imageProcessor = newImage.getProcessor();
		for(int x = 0; x < 40; x++){
			for(int y = 0; y < 40; y++){
				imageProcessor.putPixel(x, y, 100);
			}
		}
		newImage.show();
	}
}



