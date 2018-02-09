package avdw.haxe;

import haxe.Serializer;
import haxe.crypto.Md5;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Haxe 
{

	public function new() 
	{
		
	}
	
	static inline public function md5(obj:Dynamic):String
	{
		return Md5.encode(Serializer.run(obj));
	}
}