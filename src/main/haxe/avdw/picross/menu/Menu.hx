package avdw.picross.menu;

import avdw.create.grid.Grid;
import avdw.pattern.Memento;
import format.SVG;
import haxe.Json;
import haxe.Serializer;
import haxe.crypto.Md5;
import openfl.Assets;
import openfl.events.Event;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.text.TextField;
import openfl.text.TextFormatAlign;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Menu extends Sprite
{
	var lvlData:Dynamic;

	public function new()
	{
		super();
		lvlData = Json.parse(Assets.getText("json/level.json"));
		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function start(e:Event):Void
	{

		var memento:Memento = new Memento(lvlData);
		
		var xTtl = 5, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = 11, yPxlHght = stage.stageHeight / yTtl;
		var size = Math.min(xPxlWdth, yPxlHght);

		var bgGrid = Grid.create(yTtl,xTtl, cast size, true);
		bgGrid.alpha = .3;
		addChild(bgGrid);

		var svg = new SVG(Assets.getText("img/menu-button.svg"));

		for (i in 0...lvlData.directories.length)
		{
			trace(lvlData.directories[i]);
			
			var btn = new Sprite();
			var btnBg = new Sprite();
			var text = new TextField();
			
			btn.addChild(btnBg);
			btn.addChild(text);
			addChild(btn);
			
			svg.render(btnBg.graphics);
			btnBg.width = 3 * size;
			btnBg.height = 1 * size;
			
			trace(Md5.encode(Serializer.run(lvlData.directories[i])));
			
			text.text = lvlData.directories[i].name;
			text.width = btn.width;
			text.height = btn.height;
			text.selectable = false;
			
			text.getTextFormat().align = TextFormatAlign.CENTER;
			
			btn.x = 1 * size;
			btn.y = i * size;

			btn.addEventListener(MouseEvent.CLICK, btnClick);
		}

	}
	
	function btnClick(e:MouseEvent):Void 
	{
		trace(e.currentTarget);
	}

}