using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using System.Diagnostics;


namespace PurpleSpace.src.Particles
{
public class Particle
    {
        public int liveTime { get; set; }                // Время жизни частички
        public float size { get; set; }                // Размеры
        protected Texture2D texture { get; set; }        // Текстура нашей частички
        protected Vector2 position;                     // Позиция частички
        protected Vector2 velocity { get; set; }        // Скорость частички
        protected float angle { get; set; }            // Угол поворота частички
        protected float angularVelocity { get; set; }    // Угловая скорость
        protected Vector4 color { get; set; }            // Цвет частички
        protected float sizeVel { get; set; }		// Скорость уменьшения размера
        protected float alphaVel { get; set; }		// Скорость уменьшения альфы


        public Particle(Texture2D texture, Vector2 position, Vector2 velocity,
            float angle, float angularVelocity, Vector4 color, float size, int ttl, float sizeVel, float alphaVel) // конструктор
        {
            this.texture = texture;
            this.position = position;
            this.velocity = velocity;
            this.angle = angle;
            this.color = color;
            this.angularVelocity = angularVelocity;
            this.size = size;
            this.sizeVel = sizeVel;
            this.alphaVel = alphaVel;
            this.liveTime = ttl;
        }

        public virtual void Update() // цикл обновления
        {
            liveTime--; // уменьшаем время жизни

            // Меняем параметры в соответствии с скоростями
            position += new Vector2(velocity.X, velocity.Y);
            angle += angularVelocity;
            size += sizeVel;
            
            color = new Vector4(color.X, color.Y, color.Z, color.W - alphaVel); // убавляем цвет. Кстати, цвет записан в Vector4, а не в Color, потому что: Color.R/G/B имеет тип Byte (от 0x00 до 0xFF), чтобы не проделывать лишней трансформации, используем float и Vector4

        }


        public void Draw(SpriteBatch spriteBatch)
        {
                Rectangle sourceRectangle = new Rectangle(0, 0, texture.Width, texture.Height); // область из текстуры: вся
                Vector2 origin = new Vector2(texture.Width / 2, texture.Height / 2); // центр
              
               // double angleR=0;
            /*
                if (velocity.X < 0) { angleR =3.14+ Math.Asin(-velocity.Y / Math.Sqrt(velocity.Y * velocity.Y + velocity.X * velocity.X)); }
                else 
                angleR = Math.Asin(velocity.Y / Math.Sqrt(velocity.Y * velocity.Y + velocity.X * velocity.X));
            */
                spriteBatch.Draw(texture, new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, new Color(color),
                    (float)angle, origin, Game1.scale, SpriteEffects.None, 0); // акт прорисовки

        }

    }
}

