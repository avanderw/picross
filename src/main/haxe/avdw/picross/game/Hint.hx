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
	var unbroken:Bool;
	var count:Int;
	var color:Int;
	var game:Game;

	public function new(game:Game, color:Int, count:Int, unbroken:Bool)
	{
		super();
		this.game = game;
		this.color = color;
		this.count = count;
		this.unbroken = unbroken;

		var textField = new TextField();
		textField.text = "" + count;
		textField.textColor = color;
		textField.width = game.gridSize;
		textField.autoSize = TextFieldAutoSize.CENTER;
		textField.y = (game.gridSize - textField.textHeight) / 2;
		addChild(textField);
	}

}