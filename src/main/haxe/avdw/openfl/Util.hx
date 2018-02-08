package avdw.openfl;

import format.SVG;
import haxe.Serializer;
import haxe.crypto.Md5;
import openfl.display.Sprite;
import openfl.text.TextField;
import openfl.text.TextFieldAutoSize;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Util 
{

	public function new() 
	{
		
	}
	
	static inline public function createBtn(text:String, width:Int, height:Int, svg:SVG):Sprite {
		var btn = new Sprite();
		var bg = new Sprite();
		var txt = new TextField();
		
		svg.render(bg.graphics);
		bg.width = width;
		bg.height = height;
		
		txt.text = text;
		txt.width = width;
		txt.height = height;
		txt.selectable = false;
		txt.autoSize = TextFieldAutoSize.CENTER;
		
		btn.addChild(bg);
		btn.addChild(txt);
		return btn;
	}
	
	static inline public function md5(obj:Dynamic):String
	{
		return Md5.encode(Serializer.run(obj));
	}
}