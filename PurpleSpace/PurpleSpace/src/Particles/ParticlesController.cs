using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace PurpleSpace.src.Particles
{
    public abstract class ParticlesController<T> where T : Particle
    {
        protected List<T> particles;

        protected int numberOfParticles { get; set; }

        protected List<Texture2D> textureParticle; 

        protected Random random;

        public ParticlesController()
        {
            //numberOfParticles = 10;
            this.particles = new List<T>();
            random = new Random();
            textureParticle = new List<Texture2D>();
        }

        public void AddTexture(Texture2D texture)
        {
            textureParticle.Add(texture);
        }

        protected virtual Particle GenerateNewParticle(Texture2D texture, Vector2 position, Vector2 velocity,
            float angle, float angularVelocity, Vector4 color, float size, int ttl, float sizeVel, float alphaVel, Vector2 VelocityFireman) // генерация новой частички
        {
            Particle particle = new Particle(texture, position, velocity, angle, angularVelocity, color, size, ttl, sizeVel, alphaVel);
            particles.Add((T)particle);
            return particle;
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            for (int index = 0; index < particles.Count; index++) // рисуем все частицы
            {
                particles[index].Draw(spriteBatch);
            }

        }

        protected Vector2 AngleToV2(float angle, float length)
        {
            Vector2 direction = Vector2.Zero;
            direction.X = (float)Math.Cos(angle) * length;
            direction.Y = -(float)Math.Sin(angle) * length;
            return direction;
        }


        public abstract void generateParticles(Vector2 position, bool directionOfEmissionRight, Vector2 VelocityFireman);
        public abstract void Update();
    }
}
