import 'package:flutter/material.dart';

void main(List<String> args) {
  runApp(MaterialApp(
    theme: ThemeData.light(),
    home: Home(),
  ));
}

class Home extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          '多吃韩66',
        ),
        centerTitle: true,
        backgroundColor: Colors.lightBlue,
      ),

      body: FadeInImage(
        placeholder: AssetImage('images/001.jpg'),
        image: NetworkImage('https://api.cyrilstudio.top/bing/image.php'),
        imageErrorBuilder: (context, error, stackTrace) {
          return Image.asset('images/001.jpg');
        },
      ),

      // body: Image.network(
      //   'https://api.cyrilstudio.top/bing/image.php',
      // ),
      // body: CircleAvatar(
      //   backgroundImage:
      //       NetworkImage('https://api.cyrilstudio.top/bing/image.php'),
      //   radius: 50,
      // ),
    );
  }
}
