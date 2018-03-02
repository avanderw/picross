package avdw.picross.game;
import flash.display.Sprite;
import openfl.text.TextField;
import openfl.text.TextFieldAutoSize;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Hint extends Sprite
{
	public var broken:Bool;
	public var count:Int;
	public var color:Int;
	var game:Game;

	public function new(game:Game, color:Int, count:Int, broken:Bool)
	{
		super();
		this.game = game;
		this.color = color;
		this.count = count;
		this.broken = broken;
		
		if (!broken) {
			var bg = new Sprite();
			bg.graphics.beginFill(0xcccccc);
			bg.graphics.drawRect(0, 0, game.gridSize, game.gridSize);
			bg.graphics.endFill();
			addChild(bg);
		}

		var textField = new TextField();
		textField.text = "" + count;
		textField.textColor = color;
		textField.width = game.gridSize;
		textField.autoSize = TextFieldAutoSize.CENTER;
		textField.y = (game.gridSize - textField.textHeight) / 2;
		addChild(textField);
		
		if (count == 0) {
			alpha = 0;
		}
	}

}