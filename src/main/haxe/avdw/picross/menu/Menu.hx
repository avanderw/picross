package avdw.picross.menu;

import avdw.create.grid.Grid;
import avdw.pattern.Memento;
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
import openfl.text.TextFormatAlign;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Menu extends Sprite
{
	var menuBtns:Array<Sprite> = new Array();
	var directoryMap:Map<String, Dynamic> = new StringMap();

	var directoryData:Dynamic;
	var gridSize:Int;
	var menuMemento:Memento;
	var svg:SVG;
	var backBtn:Sprite;

	public function new()
	{
		super();
		directoryData = Json.parse(Assets.getText("json/level.json"));
		menuMemento = new Memento(directoryData);

		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function start(e:Event):Void
	{
		trace("start");
		svg = new SVG(Assets.getText("img/menu-button.svg"));
		
		var xTtl = 5, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = 11, yPxlHght = stage.stageHeight / yTtl;
		gridSize = cast Math.min(xPxlWdth, yPxlHght);

		var bgGrid = Grid.create(yTtl,xTtl, gridSize);
		bgGrid.alpha = .3;
		addChild(bgGrid);
		
		backBtn = new Sprite();
		var backBtnBg:Sprite = new Sprite();
		var backBtnText:TextField = new TextField();
		
		svg.render(backBtnBg.graphics);
		backBtnBg.width = 3 * gridSize;
		backBtnBg.height = 1 * gridSize;
		
		backBtnText.text = "back";
		backBtnText.width = backBtnBg.width;
		backBtnText.height = backBtnBg.height;
		backBtnText.selectable = false;
		backBtnText.getTextFormat().align = TextFormatAlign.CENTER;
		
		backBtn.addChild(backBtnBg);
		backBtn.addChild(backBtnText);
		addChild(backBtn);
		
		backBtn.addEventListener(MouseEvent.CLICK, function (event) {
			trace("click,back");
			menuMemento.restore();
			destroyMenu();
			buildMenu();
		});
		
		buildMenu();
	}

	function buildMenu():Void {
		trace("building",directoryData);
		for (i in 0...directoryData.directories.length)
		{
			var directoryBtn = new Sprite();
			var btnBg = new Sprite();
			var text = new TextField();

			directoryBtn.addChild(btnBg);
			directoryBtn.addChild(text);
			addChild(directoryBtn);

			svg.render(btnBg.graphics);
			btnBg.width = 3 * gridSize;
			btnBg.height = 1 * gridSize;

			var key = md5(directoryData.directories[i]);
			directoryMap.set(key, directoryData.directories[i]);
			directoryBtn.name = key;

			text.text = directoryData.directories[i].name;
			text.width = directoryBtn.width;
			text.height = directoryBtn.height;
			text.selectable = false;

			text.getTextFormat().align = TextFormatAlign.CENTER;

			directoryBtn.x = 1 * gridSize;
			directoryBtn.y = i * gridSize;

			directoryBtn.addEventListener(MouseEvent.CLICK, directoryClick);
			menuBtns.push(directoryBtn);
		}
		
		backBtn.x = 1 * gridSize;
		backBtn.y = directoryData.directories.length * gridSize;
	}
	
	function directoryClick(e:MouseEvent):Void
	{
		var key:String = cast (e.currentTarget, Sprite).name;
		trace("click",key,directoryMap[key]);
		menuMemento.save();
		
		for (field in Reflect.fields(directoryMap[key])) {
			Reflect.setField(directoryData, field, Reflect.field(directoryMap[key], field));
		}
		
		destroyMenu();
		buildMenu();
	}
	
	function destroyMenu() {
		trace("destroyMenu");
		var btn = menuBtns.pop();
		while (btn != null)
		{
			btn.removeEventListener(MouseEvent.CLICK, directoryClick);
			removeChild(btn);
			btn = menuBtns.pop();
		}
		
	}
	
	inline function md5(obj:Dynamic):String {
		return Md5.encode(Serializer.run(obj));
	}

}