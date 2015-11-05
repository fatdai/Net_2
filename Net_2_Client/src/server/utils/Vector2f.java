package server.utils;

public class Vector2f {
	public float x;
	public float y;
	public float w;

	public Vector2f() {
		this.x = 0.0f;
		this.y = 0.0f;
		this.w = 1.0f;
	}

	public Vector2f(Vector2f v) {
		this.x = v.x;
		this.y = v.y;
		this.w = v.w;
	}

	public Vector2f(float x, float y) {
		this.x = x;
		this.y = y;
		this.w = 1.0f;
	}

	public Vector2f(float x, float y, float w) {
		this.x = x;
		this.y = y;
		this.w = w;
	}

	public void translate(float tx, float ty) {
		x += tx;
		y += ty;
	}

	public void scale(float sx, float sy) {
		x *= sx;
		y *= sy;
	}

	public void rotate(float rad) {
		float tmp = (float) (x * Math.cos(rad) - y * Math.sin(rad));
		y = (float) (x * Math.sin(rad) + y * Math.cos(rad));
		x = tmp;
	}

	public void shear(float sx, float sy) {
		float tmp = x + sx * y;
		y = y + sy * x;
		x = tmp;
	}

	// ------------------------------------------------
	public Vector2f inv() {
		return new Vector2f(-x, -y);
	}

	public Vector2f add(Vector2f v) {
		return new Vector2f(x + v.x, y + v.y);
	}

	public Vector2f sub(Vector2f v) {
		return new Vector2f(x - v.x, y - v.y);
	}

	public Vector2f mul(float scalar) {
		return new Vector2f(scalar * x, scalar * y);
	}

	public Vector2f div(float scalar) {
		return new Vector2f(x / scalar, y / scalar);
	}

	public float len() {
		return (float) Math.sqrt(x * x + y * y);
	}

	public float cross(Vector2f v) {
		return (x * v.y - y * v.x);
	}

	public float lenSqr() {
		return x * x + y * y;
	}

	public Vector2f norm() {
		return div(len());
	}

	// 求得与this向量垂直的向量
	// 与this垂直的有两个 (y,-x) 和 (-y,x)
	// 此方法返回 从this向量开始 逆时针的第一个
	public Vector2f perp() {
		return new Vector2f(-y, x);
	}

	public float dot(Vector2f v) {
		return x * v.x + y * v.y;
	}

	// 注意:返回的是弧度
	public float rad() {
		return (float) Math.atan2(y, x);
	}

	public static Vector2f polar(float rad, float radius) {
		return new Vector2f(radius * (float) Math.cos(rad), radius
				* (float) Math.sin(rad));
	}

	@Override
	public String toString() {
		return String.format("(%s,%s)", x, y);
	}
}
