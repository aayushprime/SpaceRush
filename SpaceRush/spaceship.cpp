#include "spaceship.h"
Spaceship::Spaceship(int a):m_playerid(a),m_angle(0)
{
    healthbar.setSize({ static_cast<float>(m_health), 15 });
    healthbar.setFillColor(sf::Color::Cyan);
    healthbar.setOutlineColor(sf::Color::White);
    healthbar.setOutlineThickness(2);
    if (a == 0)
    {
        shipTex.load(Textures::BlueSpaceship, "Assets/bluespaceship.png");
        spaceship.setTexture(shipTex.get(Textures::BlueSpaceship));
        spaceship.setOrigin({
            spaceship.getGlobalBounds().width / 2 + spaceship.getOrigin().x,
            spaceship.getGlobalBounds().height / 2 + spaceship.getOrigin().y
            });
        spaceship.setPosition({500,500});
        healthbar.setPosition(100, 1000);
    }
    if (a == 1)
    {
        shipTex.load(Textures::RedSpaceship, "Assets/redspaceship.png");
        spaceship.setTexture(shipTex.get(Textures::RedSpaceship));
        spaceship.setOrigin({
            spaceship.getGlobalBounds().width / 2 + spaceship.getOrigin().x,
            spaceship.getGlobalBounds().height / 2 + spaceship.getOrigin().y
            });
        spaceship.setPosition({ 800, 800 });
        healthbar.setPosition(900, 1000);
    }
    spaceship.scale({ 0.3,0.3 });
    
}

void Spaceship::destroy() { m_destroyed = true; }

void Spaceship::move(sf::Vector2f pos)
{
    spaceship.move(-pos);
}
void Spaceship::setAngle(float angle)
{
    m_angle = angle;
    spaceship.setRotation(angle);
}


void Spaceship::decreaseHealth(int amount)
{
    if (m_health <= 10)
    {
        destroy();
    }
    m_health = m_health - amount;
    healthbar.setSize({ static_cast<float>(m_health), 15 });
}

sf::FloatRect Spaceship::getBounds()
{
    return spaceship.getGlobalBounds();
}

unsigned int Spaceship::getHealth() { return m_health; }

bool Spaceship::checkDestroyed() { return m_destroyed; }

sf::Vector2f Spaceship::getPosition() { return spaceship.getPosition(); }

void Spaceship::setPosition(sf::Vector2f position)
{
    spaceship.setPosition(position);
}

void Spaceship::setHealth(unsigned int l_health) { m_health = l_health; }

float Spaceship::getAngle() { return m_angle; }


void Spaceship::render(sf::RenderTarget& l_window)
{
    l_window.draw(spaceship);
    l_window.draw(healthbar);
}