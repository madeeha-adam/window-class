#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
  sf::RenderWindow window(sf::VideoMode(1080, 720),
                          "Bouncing mushroom");
  //Creating our shape
  sf::Texture mushroomTexture;
  mushroomTexture.loadFromFile("mushroom.png");
  sf::Sprite mushroom(mushroomTexture);
  sf::Vector2u size = mushroomTexture.getSize();
  mushroom.setOrigin(size.x / 2, size.y / 2);
  sf::Vector2f increment(0.4f, 0.4f);


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        // close window button clicked
        window.close();
      }
    }

    if((mushroom.getPosition().x + (size.x / 2) >
        window.getSize().x && increment.x > 0) ||
       (mushroom.getPosition().x - (size.x / 2) < 0 &&
        increment.x < 0))
      {
        //Reverse the direction on X axis.
        increment.x = -increment.x;
      }

    if((mushroom.getPosition().y + (size.y / 2) >
        window.getSize().y && increment.y > 0) ||
       (mushroom.getPosition().y - (size.y / 2) < 0 &&
        increment.y < 0))

      { // Reverse the direction on Y axis.
        increment.y = -increment.y;
      }

    mushroom.setPosition(mushroom.getPosition() + increment);


    window.clear(sf::Color(16, 16, 16, 255)); //Dark grey.
    window. draw(mushroom); //Drawing our sprite.
    window.display();

  }
}

class Window {
public:
  Window();
  Window(const std::string& title, const sf::Vector2u& size);

  ~Window();

  void BeginDraw(); //Clear the window.
  void EndDraw(); //Display the changes.

  void Update();

  bool isDone();
  bool isFullscreen();
  sf::Vector2u GetWindowSize();

  void ToggleFullscreen();

  void Draw(sf::Drawable& drawable);
private:
  void Setup(const std::string& title,const sf::Vector2u& size);
  void Destroy();
  void Create();

  sf::RenderWindow m_window;
  sf::Vector2u m_windowSize;
  std::string m_windowTitle;
  bool m_isDone;
  bool m_isFullscreen;

};

void Setup(std::string& title, sf:: Vector2u& size);
Window::Window () { Setup ("Window", sf::Vector2u(640, 480));}

Window::Window (const std::string& title, const sf::Vector2u& size)

  Window::~Window () { Destroy(); }
void Window:: Set(const std::string& title, const sf::Vector2u& size)

// {
//m_windowTitle = title;
//m_windowSize = size;
//m_isFullscreen = false;
//m_isDone = false;
//Create();


// void Window::Create(){
//   auto style = (m_isFullscreen ? sf::Style::Fullscreen
//                 : sf::Style::Default);
//   m_window.create({m_windowSize.y, 32},
//                   m_windowTitle, style);
// }

// auto style = sf::Style::Resize | sf::Style::Close;

// void Window::Update(){
//   sf::Event event;
//   while(m_window.pollEvent(event)){
//     if(event.type == sf::Event::Closed){
//       m_isDone = true;
//     } else if(event.type == sf::Event::KeyPressed &&
//               event.key.code == sf::Keyboard::F5)
//       {
//         ToggleFullscreen();
//       }
//   }
// }

// void Window::ToggleFullscreen(){
//   m_isFullscreen = !m_isFullscreen;
//   Destroy();
//   Create();
// }

// void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
// void Window::EndDraw() { m_window.display(); }

// bool Window::isDone() { return m_isDone; }
// bool Window:: isFullscreen() {return m_isFullscreen; }
// sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }

// void Window::Draw(sf::Drawable&1_drawable){
//   m_window.draw(1_drawable);
// }
  }
