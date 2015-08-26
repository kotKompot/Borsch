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
    class WaterParticlesController :  ParticlesController<WaterParticle>
    {
        private bool directionOfEmissionRight;
        private Random random;
        public WaterParticlesController(int numberOfParticles) : base()
        {
            this.numberOfParticles = numberOfParticles;
        }

        public override void generateParticles(Vector2 position, bool directionOfEmissionRight, Vector2 VelocityFireman) 
        {
            random = new Random();
            for (int a = 0; a < numberOfParticles; a++) 
            {
                //Vector2 velocity = AngleToV2((float)(Math.PI * 2d * random.NextDouble()), 1.5f);
                Vector2 velocity = new Vector2(3,0);
                float angle = 0;
                float angleVel = 0f;
                Vector4 color = new Vector4(1.0f, 1.0f, 1.0f, 1.0f);
                //float size = Game1.scale;
                int ttl = 20;          //good stream 40
                float sizeVel = 0;
                float alphaVel = 0.04f; //good stream 0.04f
                this.directionOfEmissionRight = directionOfEmissionRight;
                if (!directionOfEmissionRight) { angle += 3.141f; }
                GenerateNewParticle(textureParticle[0], position, velocity, angle, angleVel, color, 1, ttl, sizeVel, alphaVel, VelocityFireman);
            }
        }

        override protected Particle GenerateNewParticle(Texture2D texture, Vector2 position, Vector2 velocity,
        float angle, float angularVelocity, Vector4 color, float size, int ttl, float sizeVel, float alphaVel, Vector2 VelocityFireman) // генерация новой частички
        {
            WaterParticle particle = new WaterParticle(texture, position, velocity, angle, angularVelocity, color, size, ttl, sizeVel, alphaVel,
                                                       new Vector2(position.X, position.Y), directionOfEmissionRight, random, VelocityFireman);
            particles.Add(particle);
            return particle;
        }

        public override void Update()
        {
            for (int particle = 0; particle < particles.Count; particle++)
            {
                particles[particle].Update();
                if (particles[particle].size <= 0 || particles[particle].liveTime <= 0) // если время жизни частички или её размеры равны нулю, удаляем её
                {
                    particles.RemoveAt(particle);
                    particle--;
                }
            }



        }

    }
}