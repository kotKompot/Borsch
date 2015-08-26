using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace PurpleSpace.src.Particles
{
    class WaterParticle : Particle
    {
        Vector2 FirstPosition;
        private bool directionOfEmissionRight;
        private Random random;
        private float AdditionalEnergyX = 0;
        private float AdditionalEnergyY = 0;
        private const int ManageParabola = 40000;
        private Vector2 VelocityFireman;

          public WaterParticle(Texture2D texture, Vector2 position, Vector2 velocity,
                               float angle, float angularVelocity, Vector4 color, float size,
                               int ttl, float sizeVel, float alphaVel, Vector2 FirstPosition, bool directionOfEmissionRight, Random random, Vector2 VelocityFireman) 
              : base(texture,position,velocity, angle,angularVelocity, color,  size, ttl, sizeVel,  alphaVel)
          {
              this.FirstPosition = FirstPosition;
              this.directionOfEmissionRight = directionOfEmissionRight;
              this.random = random;
              this.position = new Vector2(position.X, position.Y + random.Next(0, 3));
              AdditionalEnergyX = (float)random.NextDouble() * 5;
              AdditionalEnergyY = ((float)random.NextDouble()-0.5f) * 3 + VelocityFireman.Y/10;
              this.VelocityFireman = new Vector2(VelocityFireman.X, VelocityFireman.Y);
          }

          override public void Update()
          {  
            liveTime--;
  
            //FirstPosition.X += VelocityFireman.X;

            if (directionOfEmissionRight)
            {
                position += new Vector2(velocity.X + AdditionalEnergyX, (position.X - FirstPosition.X) * (position.X - FirstPosition.X) / ManageParabola + AdditionalEnergyY);
            }
            else
            {
                position += new Vector2(-velocity.X - AdditionalEnergyX, (position.X - FirstPosition.X) * (position.X - FirstPosition.X) / ManageParabola + AdditionalEnergyY);
            }
            position.X += VelocityFireman.X;
            VelocityFireman.Y += 0.2f;
            position.Y += VelocityFireman.Y;
            angle += angularVelocity;
            size += sizeVel;
            
            color = new Vector4(color.X, color.Y, color.Z, color.W - alphaVel); // убавляем цвет. Кстати, цвет записан в Vector4, а не в Color, потому что: Color.R/G/B имеет тип Byte (от 0x00 до 0xFF), чтобы не проделывать лишней трансформации, используем float и Vector4

        
          }
        
    }
}
