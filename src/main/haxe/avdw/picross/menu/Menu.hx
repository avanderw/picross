package avdw.picross.menu;

import avdw.create.grid.Grid;
import format.SVG;
import haxe.Json;
import haxe.Serializer;
import haxe.crypto.Md5;
import haxe.ds.StringMap;
import openfl.Assets;
import openfl.events.Event;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.text.TextField;
import openfl.text.TextFieldAutoSize;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Menu extends Sprite
{
	var menuBtns:Array<Sprite> = new Array();
	var menuHistory:Array<String> = new Array();
	var menuIdx:String;
	
	var directoryMap:Map<String, Dynamic> = new StringMap();

	var gridSize:Int;
	var svg:SVG;
	var backBtn:Sprite;

	public function new()
	{
		super();
		
		var directoryData = Json.parse(Assets.getText("json/level.json"));
		mapDirectory(directoryData);
		
		menuIdx = md5(directoryData);
		
		svg = new SVG(Assets.getText("img/menu-button.svg"));
		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function mapDirectory(dir:Dynamic):Void
	{
		directoryMap.set(md5(dir), dir);
		for (i in 0...dir.directories.length)
		{
			mapDirectory(dir.directories[i]);
		}
	}

	function start(e:Event):Void
	{	
		var xTtl = 5, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = 11, yPxlHght = stage.stageHeight / yTtl;
		gridSize = cast Math.min(xPxlWdth, yPxlHght);

		var bgGrid = Grid.create(yTtl,xTtl, gridSize);
		bgGrid.alpha = .3;
		addChild(bgGrid);

		backBtn = createBtn("back");
		addChild(backBtn);

		backBtn.addEventListener(MouseEvent.CLICK, function (event)
		{
			trace("click,back");
			menuIdx = menuHistory.pop();
			
			destroyMenu();
			buildMenu();
		});

		buildMenu();
	}
	
	function createBtn(text:String):Sprite {
		var btn = new Sprite();
		var bg = new Sprite();
		var txt = new TextField();
		
		svg.render(bg.graphics);
		bg.width = 3 * gridSize;
		bg.height = 1 * gridSize;
		
		txt.text = text;
		txt.selectable = false;
		txt.autoSize = TextFieldAutoSize.CENTER;
		
		btn.addChild(bg);
		btn.addChild(txt);
		return btn;
	}

	function buildMenu():Void
	{
		trace("building", menuIdx);
		
		for (i in 0...directoryMap[menuIdx].directories.length)
		{
			var directoryBtn = createBtn(directoryMap[menuIdx].directories[i].name);
			directoryBtn.name = md5(directoryMap[menuIdx].directories[i]);
			addChild(directoryBtn);

			directoryBtn.x = 1 * gridSize;
			directoryBtn.y = i * gridSize;

			directoryBtn.addEventListener(MouseEvent.CLICK, directoryClick);
			menuBtns.push(directoryBtn);
		}

		backBtn.x = 1 * gridSize;
		backBtn.y = directoryMap[menuIdx].directories.length * gridSize;
	}

	function directoryClick(e:MouseEvent):Void
	{
		var key:String = cast (e.currentTarget, Sprite).name;
		trace("click", key);
		menuHistory.push(menuIdx);
		menuIdx = key;
	
		destroyMenu();
		buildMenu();
	}

	function destroyMenu()
	{
		var btn = menuBtns.pop();
		while (btn != null)
		{
			btn.removeEventListener(MouseEvent.CLICK, directoryClick);
			removeChild(btn);
			btn = menuBtns.pop();
		}

	}

	inline function md5(obj:Dynamic):String
	{
		return Md5.encode(Serializer.run(obj));
	}

}